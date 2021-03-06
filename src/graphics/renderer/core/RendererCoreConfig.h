#pragma once

#include <string>

#ifndef __APPLE__
#include "generated/flextGL.h"
#else
#define GLFW_INCLUDE_GLCOREARB
#define flextInit
#include "GLFW/glfw3.h"
#endif

/**
* Defines the default application-to-shader interface.
* TODO Cleanup?
*/

// Vertex array data locations
const GLuint vertexDataShaderLocation = 0;
const GLuint normalDataShaderLocation = 1;
const GLuint uvDataShaderLocation = 2;

// Screen parameters
const std::string screenWidthUniformName = "screen_width";
const std::string screenHeightUniformName = "screen_height";

// Camera parameters
const std::string cameraPositionUniformName = "camera_position";
const std::string cameraDirectionUniformName = "camera_direction";
const std::string viewDistanceUniformName = "view_distance"; // TODO Rename, same as z-far?
const std::string cameraZNearUniformName = "camera_z_near";
const std::string cameraZFarUniformName = "camera_z_far";

// Depth-of-field parameters
const std::string focusNearUniformName = "focus_near";
const std::string focusFarUniformName = "focus_far";
const std::string blurNearUniformName = "blur_near";
const std::string blurFarUniformName = "blur_far";

// Blur parameters
const std::string blurStrengthUniformName = "blur_strength";

// Fog parameters
const std::string fogPassTypeUniformName = "fog_type";

// View and perspective matrix uniform names
const std::string viewMatrixUniformName = "view";
const std::string inverseViewMatrixUniformName = "inverse_view";
const std::string projectionMatrixUniformName = "projection";
const std::string inverseProjectionMatrixUniformName = "inverse_projection";
const std::string viewProjectionMatrixUniformName = "view_projection";
const std::string inverseViewProjectionMatrixUniformName = "inverse_view_projection";
const std::string shadowViewProjectionBiasMatrixUniformName = "shadow_view_projection_bias";

// Transformation matrix uniform names
const std::string rotationMatrixUniformName = "rotation";
const std::string translationMatrixUniformName = "translation";
const std::string scaleMatrixUniformName = "scale";
const std::string modelMatrixUniformName = "model";
const std::string modelViewProjectionMatrixUniformName = "model_view_projection";

// Light parameter uniform names
const std::string lightPositionUniformName = "light_position";
const std::string lightPositionScreenUniformName = "light_position_screen";
const std::string lightDirectionUniformName = "light_direction";
const std::string lightRadiusUniformName = "light_radius";
const std::string lightIntensityUniformName = "light_intensity";
const std::string lightColorUniformName = "light_color";

// Texture units for geometry pass material textures
const GLint diffuseTextureUnit = 0;
const GLint normalTextureUnit = 1;
const GLint specularTextureUnit = 2;
const GLint glowTextureUnit = 3;
const GLint alphaTextureUnit = 4;

// Texture units for light pass
const GLint lightPassDepthTextureUnit = 0;
const GLint lightPassNormalSpecularTextureUnit = 1;
const GLint lightPassShadowMapTextureUnit = 2; // Should be lightPassShadowTextureUnit

// Texture units for illumination pass
const GLint illuminationPassLightTextureUnit = 0;
const GLint illuminationPassDiffuseGlowTextureUnit = 1;
const GLint illuminationPassDepthTextureUnit = 2;

// Texture units for fog pass
const GLint fogPassSceneTextureUnit = 0;
const GLint fogPassDepthTextureUnit = 1;

// Texture units for display pass
const GLint displayPassSceneTextureUnit = 0;

// Texture units for FXAA pass
const GLint fxaaPassInputTextureUnit = 0;

// Texture units for vertical gauss blur pass
const GLint gaussBlurVerticalPassInputTextureUnit = 0;

// Texture units for horiontal gauss blur pass
const GLint gaussBlurHoriontalPassInputTextureUnit = 0;

// Texture units for god ray pass 1 (ray generation)
const GLint godRayPass1InputTextureUnit = 0;
const GLint godRayPass1DepthTextureUnit = 1;

// Texture units for god ray pass 2 (blending)
const GLint godRayPass2SceneTextureUnit = 0;
const GLint godRayPass2GodRayTextureUnit = 1;

// Texture units for depth-of-field pass
const GLint depthOfFieldPassSceneTextureUnit = 0;
const GLint depthOfFieldPassBlurTextureUnit = 1;
const GLint depthOfFieldPassDepthTextureUnit = 2;

// Texture units for depth texture visualization pass
const GLint visualizeDepthPassDepthTextureUnit = 0;

// Texture sampler uniform names
const std::string diffuseTextureUniformName = "diffuse_texture";
const std::string normalTextureUniformName = "normal_texture";
const std::string specularTextureUniformName = "specular_texture";
const std::string glowTextureUniformName = "glow_texture";
const std::string alphaTextureUniformName = "alpha_texture";
const std::string depthTextureUniformName = "depth_texture";
const std::string normalSpecularTextureUniformName = "normal_specular_texture";
const std::string diffuseGlowTextureUniformName = "diffuse_glow_texture";
const std::string lightTextureUniformName = "light_texture";
const std::string shadowMapTextureUniformName = "shadow_map"; // Should be shadow_map_texture or shadow_texture
const std::string shadowCubeTextureUniformName = "shadow_cube";
const std::string sceneTextureUniformName = "scene_texture";
const std::string blurTextureUniformName = "blur_texture";
const std::string godRayTextureUniformName = "godray_texture";

// Generic texture names
const std::string texture0UniformName = "texture0";
const std::string texture1UniformName = "texture1";
const std::string texture2UniformName = "texture2";
const std::string texture3UniformName = "texture3";
const std::string texture4UniformName = "texture4";

// Generic texture units
const GLint texture0TextureUnit = 0;
const GLint texture1TextureUnit = 1;
const GLint texture2TextureUnit = 2;
const GLint texture3TextureUnit = 3;
const GLint texture4TextureUnit = 4;