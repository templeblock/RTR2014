#include "CShaderProgram.h"

#include <cassert>

#include <glm/ext.hpp>

GLuint CShaderProgram::s_activeShaderProgram = 0;

CShaderProgram::CShaderProgram(TShaderObject<GL_VERTEX_SHADER>* vertex,
                               TShaderObject<GL_TESS_CONTROL_SHADER>* tessControl,
							   TShaderObject<GL_TESS_EVALUATION_SHADER>* tessEval,
							   TShaderObject<GL_GEOMETRY_SHADER>* geometry,
                               TShaderObject<GL_FRAGMENT_SHADER>* fragment)
    : m_programId(0), m_valid(false)
{
	init(vertex, tessControl, tessEval, geometry, fragment);
}

CShaderProgram::~CShaderProgram()
{
    if (m_valid)
    {
        glDeleteProgram(m_programId);
    }
}

bool CShaderProgram::init(TShaderObject<GL_VERTEX_SHADER>* vertex,
                          TShaderObject<GL_TESS_CONTROL_SHADER>* tessControl,
						  TShaderObject<GL_TESS_EVALUATION_SHADER>* tessEval,
						  TShaderObject<GL_GEOMETRY_SHADER>* geometry,
                          TShaderObject<GL_FRAGMENT_SHADER>* fragment)
{
    // Needs vertex shader
    if (vertex == nullptr || !vertex->isValid())
    {
        return false;
    }
    // Need fragment shader
    if (fragment == nullptr || !fragment->isValid())
    {
        return false;
    }

    // Check if any of the other shaders are invalid
    // nullptr signals unused stage
    if (geometry != nullptr && !geometry->isValid())
    {
        return false;
    }
    else if (tessControl != nullptr && !tessControl->isValid())
    {
        return false;
    }
    else if (tessEval != nullptr && !tessEval->isValid())
    {
        return false;
    }

    // Create program id
    GLuint programId = glCreateProgram();
    // Attach shader objects after checking validity

    // Needed stages
    glAttachShader(programId, vertex->getId());
    glAttachShader(programId, fragment->getId());
    // Optional stages
    if (geometry != nullptr)
    {
        glAttachShader(programId, geometry->getId());
    }
    if (tessControl != nullptr)
    {
        glAttachShader(programId, tessControl->getId());
    }
    if (tessEval != nullptr)
    {
        glAttachShader(programId, tessEval->getId());
    }

    // Link program
    glLinkProgram(programId);
    // Check result
    GLint result;
    glGetProgramiv(programId, GL_LINK_STATUS, &result);
    if (result == GL_FALSE)
    {
        // Set info log size
        GLint size;
        glGetShaderiv(programId, GL_INFO_LOG_LENGTH, &size);
        if (size > 0)
        {
            // Create buffer
            std::vector<GLchar> log(size + 1);
            // Get log
            glGetProgramInfoLog(programId, size, NULL, log.data());
            m_infoLog.assign(log.data(), size);
        }
        // Clean up temp id
        glDeleteProgram(programId);
        return false;
    }
    // New shader program linked successfully
    // Delete old shader object
    if (m_valid)
    {
        glDeleteShader(m_programId);
    }
    // Set new id
    m_programId = programId;
    // Set validity flag
    m_valid = true;
    return true;
}

void CShaderProgram::setActive()
{
    assert(isValid());
    if (s_activeShaderProgram != m_programId)
    {
        glUseProgram(m_programId);
        s_activeShaderProgram = m_programId;
    }
}

const std::string& CShaderProgram::getErrorString() const { return m_infoLog; }

bool CShaderProgram::isValid() const { return m_valid; }

GLint CShaderProgram::getUniformLocation(const std::string& uniformName) const
{
    return glGetUniformLocation(m_programId, uniformName.data());
}

GLint CShaderProgram::getAttributeLocation(const std::string& attributeName) const
{
    return glGetAttribLocation(m_programId, attributeName.data());
}

void CShaderProgram::setUniform(GLint location, int i)
{
    setActive();
    glUniform1i(location, i);
}

void CShaderProgram::setUniform(GLint location, float f)
{
    setActive();
    glUniform1f(location, f);
}

void CShaderProgram::setUniform(GLint location, const glm::vec3& v)
{
    setActive();
    glUniform3f(location, v.x, v.y, v.z);
}

void CShaderProgram::setUniform(GLint location, const glm::vec4& v)
{
    setActive();
    glUniform4f(location, v.x, v.y, v.z, v.w);
}

void CShaderProgram::setUniform(GLint location, const glm::mat2& m)
{
    setActive();
    glUniformMatrix2fv(location, 1, GL_TRUE, glm::value_ptr(m));
}

void CShaderProgram::setUniform(GLint location, const glm::mat3& m)
{
    setActive();
    glUniformMatrix3fv(location, 1, GL_TRUE, glm::value_ptr(m));
}

void CShaderProgram::setUniform(GLint location, const glm::mat4& m)
{
    setActive();
    glUniformMatrix4fv(location, 1, GL_TRUE, glm::value_ptr(m));
}