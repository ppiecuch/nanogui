#include <nanogui/qtgl.h>
#include <qopenglcontext.h>
#include <qopenglextrafunctions.h>

/*
 * QOpenGLFunctions
 */

// GLES2 + OpenGL1 common subset
void glBindTexture(GLenum target, GLuint texture) { QOpenGLContext::currentContext()->extraFunctions()->glBindTexture(target, texture); }
void glBlendFunc(GLenum sfactor, GLenum dfactor) { QOpenGLContext::currentContext()->extraFunctions()->glBlendFunc(sfactor, dfactor); }
void glClear(GLbitfield mask) { QOpenGLContext::currentContext()->extraFunctions()->glClear(mask); }
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { QOpenGLContext::currentContext()->extraFunctions()->glClearColor(red, green, blue, alpha); }
void glClearStencil(GLint s) { QOpenGLContext::currentContext()->extraFunctions()->glClearStencil(s); }
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { QOpenGLContext::currentContext()->extraFunctions()->glColorMask(red, green, blue, alpha); }
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { QOpenGLContext::currentContext()->extraFunctions()->glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
void glCullFace(GLenum mode) { QOpenGLContext::currentContext()->extraFunctions()->glCullFace(mode); }
void glDeleteTextures(GLsizei n, const GLuint *textures) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteTextures(n, textures); }
void glDepthFunc(GLenum func) { QOpenGLContext::currentContext()->extraFunctions()->glDepthFunc(func); }
void glDepthMask(GLboolean flag) { QOpenGLContext::currentContext()->extraFunctions()->glDepthMask(flag); }
void glDisable(GLenum cap) { QOpenGLContext::currentContext()->extraFunctions()->glDisable(cap); }
void glDrawArrays(GLenum mode, GLint first, GLsizei count) { QOpenGLContext::currentContext()->extraFunctions()->glDrawArrays(mode, first, count); }
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) { QOpenGLContext::currentContext()->extraFunctions()->glDrawElements(mode, count, type, indices); }
void glEnable(GLenum cap) { QOpenGLContext::currentContext()->extraFunctions()->glEnable(cap); }
void glFinish(void) { QOpenGLContext::currentContext()->extraFunctions()->glFinish(); }
void glFlush(void) { QOpenGLContext::currentContext()->extraFunctions()->glFlush(); }
void glFrontFace(GLenum mode) { QOpenGLContext::currentContext()->extraFunctions()->glFrontFace(mode); }
void glGenTextures(GLsizei n, GLuint *textures) { QOpenGLContext::currentContext()->extraFunctions()->glGenTextures(n, textures); }
void glGetBooleanv(GLenum pname, GLboolean *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetBooleanv(pname, data); }
GLenum glGetError(void) { return QOpenGLContext::currentContext()->extraFunctions()->glGetError(); }
void glGetFloatv(GLenum pname, GLfloat *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetFloatv(pname, data); }
void glGetIntegerv(GLenum pname, GLint *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetIntegerv(pname, data); }
const GLubyte * glGetString(GLenum name) { QOpenGLContext::currentContext()->extraFunctions()->glGetString(name); }
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetTexParameterfv(target, pname, params); }
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetTexParameteriv(target, pname, params); }
void glHint(GLenum target, GLenum mode) { QOpenGLContext::currentContext()->extraFunctions()->glHint(target, mode); }
GLboolean glIsEnabled(GLenum cap) { QOpenGLContext::currentContext()->extraFunctions()->glIsEnabled(cap); }
GLboolean glIsTexture(GLuint texture) { QOpenGLContext::currentContext()->extraFunctions()->glIsTexture(texture); }
void glLineWidth(GLfloat width) { QOpenGLContext::currentContext()->extraFunctions()->glLineWidth(width); }
void glPixelStorei(GLenum pname, GLint param) { QOpenGLContext::currentContext()->extraFunctions()->glPixelStorei(pname, param); }
void glPolygonOffset(GLfloat factor, GLfloat units) { QOpenGLContext::currentContext()->extraFunctions()->glPolygonOffset(factor, units); }
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) { QOpenGLContext::currentContext()->extraFunctions()->glReadPixels(x, y, width, height, format, type, pixels); }
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glScissor(x, y, width, height); }
void glStencilFunc(GLenum func, GLint ref, GLuint mask) { QOpenGLContext::currentContext()->extraFunctions()->glStencilFunc(func, ref, mask); }
void glStencilMask(GLuint mask) { QOpenGLContext::currentContext()->extraFunctions()->glStencilMask(mask); }
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { QOpenGLContext::currentContext()->extraFunctions()->glStencilOp(fail, zfail, zpass); }
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) { QOpenGLContext::currentContext()->extraFunctions()->glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { QOpenGLContext::currentContext()->extraFunctions()->glTexParameterf(target, pname, param); }
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glTexParameterfv(target, pname, params); }
void glTexParameteri(GLenum target, GLenum pname, GLint param) { QOpenGLContext::currentContext()->extraFunctions()->glTexParameteri(target, pname, param); }
void glTexParameteriv(GLenum target, GLenum pname, const GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glTexParameteriv(target, pname, params); }
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { QOpenGLContext::currentContext()->extraFunctions()->glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glViewport(x, y, width, height); }

// GL(ES)2
void glActiveTexture(GLenum texture) { QOpenGLContext::currentContext()->extraFunctions()->glActiveTexture(texture); }
void glAttachShader(GLuint program, GLuint shader) { QOpenGLContext::currentContext()->extraFunctions()->glAttachShader(program, shader); }
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glBindAttribLocation(program, index, name); }
void glBindBuffer(GLenum target, GLuint buffer) { QOpenGLContext::currentContext()->extraFunctions()->glBindBuffer(target, buffer); }
void glBindFramebuffer(GLenum target, GLuint framebuffer) { QOpenGLContext::currentContext()->extraFunctions()->glBindFramebuffer(target, framebuffer); }
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { QOpenGLContext::currentContext()->extraFunctions()->glBindRenderbuffer(target, renderbuffer); }
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { QOpenGLContext::currentContext()->extraFunctions()->glBlendColor(red, green, blue, alpha); }
void glBlendEquation(GLenum mode) { QOpenGLContext::currentContext()->extraFunctions()->glBlendEquation(mode); }
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { QOpenGLContext::currentContext()->extraFunctions()->glBlendEquationSeparate(modeRGB, modeAlpha); }
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { QOpenGLContext::currentContext()->extraFunctions()->glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) { QOpenGLContext::currentContext()->extraFunctions()->glBufferData(target, size, data, usage); }
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) { QOpenGLContext::currentContext()->extraFunctions()->glBufferSubData(target, offset, size, data); }
GLenum glCheckFramebufferStatus(GLenum target) { QOpenGLContext::currentContext()->extraFunctions()->glCheckFramebufferStatus(target); }
void glClearDepthf(GLfloat d) { QOpenGLContext::currentContext()->extraFunctions()->glClearDepthf(d); }
void glCompileShader(GLuint shader) { QOpenGLContext::currentContext()->extraFunctions()->glCompileShader(shader); }
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { QOpenGLContext::currentContext()->extraFunctions()->glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { QOpenGLContext::currentContext()->extraFunctions()->glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
GLuint glCreateProgram(void) { QOpenGLContext::currentContext()->extraFunctions()->glCreateProgram(); }
GLuint glCreateShader(GLenum type) { QOpenGLContext::currentContext()->extraFunctions()->glCreateShader(type); }
void glDeleteBuffers(GLsizei n, const GLuint *buffers) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteBuffers(n, buffers); }
void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteFramebuffers(n, framebuffers); }
void glDeleteProgram(GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteProgram(program); }
void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteRenderbuffers(n, renderbuffers); }
void glDeleteShader(GLuint shader) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteShader(shader); }
void glDepthRangef(GLfloat n, GLfloat f) { QOpenGLContext::currentContext()->extraFunctions()->glDepthRangef(n, f); }
void glDetachShader(GLuint program, GLuint shader) { QOpenGLContext::currentContext()->extraFunctions()->glDetachShader(program, shader); }
void glDisableVertexAttribArray(GLuint index) { QOpenGLContext::currentContext()->extraFunctions()->glDisableVertexAttribArray(index); }
void glEnableVertexAttribArray(GLuint index) { QOpenGLContext::currentContext()->extraFunctions()->glEnableVertexAttribArray(index); }
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { QOpenGLContext::currentContext()->extraFunctions()->glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { QOpenGLContext::currentContext()->extraFunctions()->glFramebufferTexture2D(target, attachment, textarget, texture, level); }
void glGenBuffers(GLsizei n, GLuint *buffers) { QOpenGLContext::currentContext()->extraFunctions()->glGenBuffers(n, buffers); }
void glGenerateMipmap(GLenum target) { QOpenGLContext::currentContext()->extraFunctions()->glGenerateMipmap(target); }
void glGenFramebuffers(GLsizei n, GLuint *framebuffers) { QOpenGLContext::currentContext()->extraFunctions()->glGenFramebuffers(n, framebuffers); }
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { QOpenGLContext::currentContext()->extraFunctions()->glGenRenderbuffers(n, renderbuffers); }
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetActiveUniform(program, index, bufSize, length, size, type, name); }
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { QOpenGLContext::currentContext()->extraFunctions()->glGetAttachedShaders(program, maxCount, count, shaders); }
GLint glGetAttribLocation(GLuint program, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetAttribLocation(program, name); }
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetBufferParameteriv(target, pname, params); }
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
void glGetProgramiv(GLuint program, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramiv(program, pname, params); }
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramInfoLog(program, bufSize, length, infoLog); }
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetRenderbufferParameteriv(target, pname, params); }
void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetShaderiv(shader, pname, params); }
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { QOpenGLContext::currentContext()->extraFunctions()->glGetShaderInfoLog(shader, bufSize, length, infoLog); }
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { QOpenGLContext::currentContext()->extraFunctions()->glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { QOpenGLContext::currentContext()->extraFunctions()->glGetShaderSource(shader, bufSize, length, source); }
void glGetUniformfv(GLuint program, GLint location, GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformfv(program, location, params); }
void glGetUniformiv(GLuint program, GLint location, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformiv(program, location, params); }
GLint glGetUniformLocation(GLuint program, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformLocation(program, name); }
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetVertexAttribfv(index, pname, params); }
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetVertexAttribiv(index, pname, params); }
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) { QOpenGLContext::currentContext()->extraFunctions()->glGetVertexAttribPointerv(index, pname, pointer); }
GLboolean glIsBuffer(GLuint buffer) { QOpenGLContext::currentContext()->extraFunctions()->glIsBuffer(buffer); }
GLboolean glIsFramebuffer(GLuint framebuffer) { QOpenGLContext::currentContext()->extraFunctions()->glIsFramebuffer(framebuffer); }
GLboolean glIsProgram(GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glIsProgram(program); }
GLboolean glIsRenderbuffer(GLuint renderbuffer) { QOpenGLContext::currentContext()->extraFunctions()->glIsRenderbuffer(renderbuffer); }
GLboolean glIsShader(GLuint shader) { QOpenGLContext::currentContext()->extraFunctions()->glIsShader(shader); }
void glLinkProgram(GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glLinkProgram(program); }
void glReleaseShaderCompiler(void) { QOpenGLContext::currentContext()->extraFunctions()->glReleaseShaderCompiler(); }
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glRenderbufferStorage(target, internalformat, width, height); }
void glSampleCoverage(GLfloat value, GLboolean invert) { QOpenGLContext::currentContext()->extraFunctions()->glSampleCoverage(value, invert); }
void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) { QOpenGLContext::currentContext()->extraFunctions()->glShaderBinary(count, shaders, binaryformat, binary, length); }
void glShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length) { QOpenGLContext::currentContext()->extraFunctions()->glShaderSource(shader, count, const_cast<const char**>(string), length); }
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { QOpenGLContext::currentContext()->extraFunctions()->glStencilFuncSeparate(face, func, ref, mask); }
void glStencilMaskSeparate(GLenum face, GLuint mask) { QOpenGLContext::currentContext()->extraFunctions()->glStencilMaskSeparate(face, mask); }
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { QOpenGLContext::currentContext()->extraFunctions()->glStencilOpSeparate(face, sfail, dpfail, dppass); }
void glUniform1f(GLint location, GLfloat v0) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1f(location, v0); }
void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1fv(location, count, value); }
void glUniform1i(GLint location, GLint v0) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1i(location, v0); }
void glUniform1iv(GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1iv(location, count, value); }
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2f(location, v0, v1); }
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2fv(location, count, value); }
void glUniform2i(GLint location, GLint v0, GLint v1) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2i(location, v0, v1); }
void glUniform2iv(GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2iv(location, count, value); }
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3f(location, v0, v1, v2); }
void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3fv(location, count, value); }
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3i(location, v0, v1, v2); }
void glUniform3iv(GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3iv(location, count, value); }
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4f(location, v0, v1, v2, v3); }
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4fv(location, count, value); }
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4i(location, v0, v1, v2, v3); }
void glUniform4iv(GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4iv(location, count, value); }
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix2fv(location, count, transpose, value); }
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix3fv(location, count, transpose, value); }
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix4fv(location, count, transpose, value); }
void glUseProgram(GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glUseProgram(program); }
void glValidateProgram(GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glValidateProgram(program); }
void glVertexAttrib1f(GLuint index, GLfloat x) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib1f(index, x); }
void glVertexAttrib1fv(GLuint index, const GLfloat *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib1fv(index, v); }
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib2f(index, x, y); }
void glVertexAttrib2fv(GLuint index, const GLfloat *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib2fv(index, v); }
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib3f(index, x, y, z); }
void glVertexAttrib3fv(GLuint index, const GLfloat *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib3fv(index, v); }
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib4f(index, x, y, z, w); }
void glVertexAttrib4fv(GLuint index, const GLfloat *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttrib4fv(index, v); }
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribPointer(index, size, type, normalized, stride, pointer); }

/*
 * QOpenGLExtraFunctions
 */

// GLES3
void glReadBuffer(GLenum src) { QOpenGLContext::currentContext()->extraFunctions()->glReadBuffer(src); }
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) { QOpenGLContext::currentContext()->extraFunctions()->glDrawRangeElements(mode, start, end, count, type, indices); }
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) { QOpenGLContext::currentContext()->extraFunctions()->glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { QOpenGLContext::currentContext()->extraFunctions()->glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) { QOpenGLContext::currentContext()->extraFunctions()->glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { QOpenGLContext::currentContext()->extraFunctions()->glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
void glGenQueries(GLsizei n, GLuint *ids) { QOpenGLContext::currentContext()->extraFunctions()->glGenQueries(n, ids); }
void glDeleteQueries(GLsizei n, const GLuint *ids) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteQueries(n, ids); }
GLboolean glIsQuery(GLuint id) { QOpenGLContext::currentContext()->extraFunctions()->glIsQuery(id); }
void glBeginQuery(GLenum target, GLuint id) { QOpenGLContext::currentContext()->extraFunctions()->glBeginQuery(target, id); }
void glEndQuery(GLenum target) { QOpenGLContext::currentContext()->extraFunctions()->glEndQuery(target); }
void glGetQueryiv(GLenum target, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetQueryiv(target, pname, params); }
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetQueryObjectuiv(id, pname, params); }
GLboolean glUnmapBuffer(GLenum target) { QOpenGLContext::currentContext()->extraFunctions()->glUnmapBuffer(target); }
void glGetBufferPointerv(GLenum target, GLenum pname, void **params) { QOpenGLContext::currentContext()->extraFunctions()->glGetBufferPointerv(target, pname, params); }
void glDrawBuffers(GLsizei n, const GLenum *bufs) { QOpenGLContext::currentContext()->extraFunctions()->glDrawBuffers(n, bufs); }
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix2x3fv(location, count, transpose, value); }
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix3x2fv(location, count, transpose, value); }
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix2x4fv(location, count, transpose, value); }
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix4x2fv(location, count, transpose, value); }
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix3x4fv(location, count, transpose, value); }
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniformMatrix4x3fv(location, count, transpose, value); }
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { QOpenGLContext::currentContext()->extraFunctions()->glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { QOpenGLContext::currentContext()->extraFunctions()->glFramebufferTextureLayer(target, attachment, texture, level, layer); }
GLvoid* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { QOpenGLContext::currentContext()->extraFunctions()->glMapBufferRange(target, offset, length, access); }
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { QOpenGLContext::currentContext()->extraFunctions()->glFlushMappedBufferRange(target, offset, length); }
void glBindVertexArray(GLuint array) { QOpenGLContext::currentContext()->extraFunctions()->glBindVertexArray(array); }
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteVertexArrays(n, arrays); }
void glGenVertexArrays(GLsizei n, GLuint *arrays) { QOpenGLContext::currentContext()->extraFunctions()->glGenVertexArrays(n, arrays); }
GLboolean glIsVertexArray(GLuint array) { QOpenGLContext::currentContext()->extraFunctions()->glIsVertexArray(array); }
void glGetIntegeri_v(GLenum target, GLuint index, GLint *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetIntegeri_v(target, index, data); }
void glBeginTransformFeedback(GLenum primitiveMode) { QOpenGLContext::currentContext()->extraFunctions()->glBeginTransformFeedback(primitiveMode); }
void glEndTransformFeedback(void) { QOpenGLContext::currentContext()->extraFunctions()->glEndTransformFeedback(); }
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { QOpenGLContext::currentContext()->extraFunctions()->glBindBufferRange(target, index, buffer, offset, size); }
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { QOpenGLContext::currentContext()->extraFunctions()->glBindBufferBase(target, index, buffer); }
void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) { QOpenGLContext::currentContext()->extraFunctions()->glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribIPointer(index, size, type, stride, pointer); }
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetVertexAttribIiv(index, pname, params); }
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetVertexAttribIuiv(index, pname, params); }
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribI4i(index, x, y, z, w); }
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribI4ui(index, x, y, z, w); }
void glVertexAttribI4iv(GLuint index, const GLint *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribI4iv(index, v); }
void glVertexAttribI4uiv(GLuint index, const GLuint *v) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribI4uiv(index, v); }
void glGetUniformuiv(GLuint program, GLint location, GLuint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformuiv(program, location, params); }
GLint glGetFragDataLocation(GLuint program, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetFragDataLocation(program, name); }
void glUniform1ui(GLint location, GLuint v0) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1ui(location, v0); }
void glUniform2ui(GLint location, GLuint v0, GLuint v1) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2ui(location, v0, v1); }
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3ui(location, v0, v1, v2); }
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4ui(location, v0, v1, v2, v3); }
void glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform1uiv(location, count, value); }
void glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform2uiv(location, count, value); }
void glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform3uiv(location, count, value); }
void glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glUniform4uiv(location, count, value); }
void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glClearBufferiv(buffer, drawbuffer, value); }
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glClearBufferuiv(buffer, drawbuffer, value); }
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glClearBufferfv(buffer, drawbuffer, value); }
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { QOpenGLContext::currentContext()->extraFunctions()->glClearBufferfi(buffer, drawbuffer, depth, stencil); }
const GLubyte *glGetStringi(GLenum name, GLuint index) { QOpenGLContext::currentContext()->extraFunctions()->glGetStringi(name, index); }
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { QOpenGLContext::currentContext()->extraFunctions()->glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { QOpenGLContext::currentContext()->extraFunctions()->glGetUniformBlockIndex(program, uniformBlockName); }
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) { QOpenGLContext::currentContext()->extraFunctions()->glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { QOpenGLContext::currentContext()->extraFunctions()->glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { QOpenGLContext::currentContext()->extraFunctions()->glDrawArraysInstanced(mode, first, count, instancecount); }
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) { QOpenGLContext::currentContext()->extraFunctions()->glDrawElementsInstanced(mode, count, type, indices, instancecount); }
GLsync glFenceSync(GLenum condition, GLbitfield flags) { QOpenGLContext::currentContext()->extraFunctions()->glFenceSync(condition, flags); }
GLboolean glIsSync(GLsync sync) { QOpenGLContext::currentContext()->extraFunctions()->glIsSync(sync); }
void glDeleteSync(GLsync sync) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteSync(sync); }
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { QOpenGLContext::currentContext()->extraFunctions()->glClientWaitSync(sync, flags, timeout); }
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { QOpenGLContext::currentContext()->extraFunctions()->glWaitSync(sync, flags, timeout); }
void glGetInteger64v(GLenum pname, GLint64 *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetInteger64v(pname, data); }
void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) { QOpenGLContext::currentContext()->extraFunctions()->glGetSynciv(sync, pname, bufSize, length, values); }
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetInteger64i_v(target, index, data); }
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetBufferParameteri64v(target, pname, params); }
void glGenSamplers(GLsizei count, GLuint *samplers) { QOpenGLContext::currentContext()->extraFunctions()->glGenSamplers(count, samplers); }
void glDeleteSamplers(GLsizei count, const GLuint *samplers) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteSamplers(count, samplers); }
GLboolean glIsSampler(GLuint sampler) { QOpenGLContext::currentContext()->extraFunctions()->glIsSampler(sampler); }
void glBindSampler(GLuint unit, GLuint sampler) { QOpenGLContext::currentContext()->extraFunctions()->glBindSampler(unit, sampler); }
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { QOpenGLContext::currentContext()->extraFunctions()->glSamplerParameteri(sampler, pname, param); }
void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) { QOpenGLContext::currentContext()->extraFunctions()->glSamplerParameteriv(sampler, pname, param); }
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { QOpenGLContext::currentContext()->extraFunctions()->glSamplerParameterf(sampler, pname, param); }
void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) { QOpenGLContext::currentContext()->extraFunctions()->glSamplerParameterfv(sampler, pname, param); }
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetSamplerParameteriv(sampler, pname, params); }
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetSamplerParameterfv(sampler, pname, params); }
void glVertexAttribDivisor(GLuint index, GLuint divisor) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribDivisor(index, divisor); }
void glBindTransformFeedback(GLenum target, GLuint id) { QOpenGLContext::currentContext()->extraFunctions()->glBindTransformFeedback(target, id); }
void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteTransformFeedbacks(n, ids); }
void glGenTransformFeedbacks(GLsizei n, GLuint *ids) { QOpenGLContext::currentContext()->extraFunctions()->glGenTransformFeedbacks(n, ids); }
GLboolean glIsTransformFeedback(GLuint id) { QOpenGLContext::currentContext()->extraFunctions()->glIsTransformFeedback(id); }
void glPauseTransformFeedback(void) { QOpenGLContext::currentContext()->extraFunctions()->glPauseTransformFeedback(); }
void glResumeTransformFeedback(void) { QOpenGLContext::currentContext()->extraFunctions()->glResumeTransformFeedback(); }
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) { QOpenGLContext::currentContext()->extraFunctions()->glProgramBinary(program, binaryFormat, binary, length); }
void glProgramParameteri(GLuint program, GLenum pname, GLint value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramParameteri(program, pname, value); }
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) { QOpenGLContext::currentContext()->extraFunctions()->glInvalidateFramebuffer(target, numAttachments, attachments); }
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { QOpenGLContext::currentContext()->extraFunctions()->glTexStorage2D(target, levels, internalformat, width, height); }
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { QOpenGLContext::currentContext()->extraFunctions()->glTexStorage3D(target, levels, internalformat, width, height, depth); }
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetInternalformativ(target, internalformat, pname, bufSize, params); }

// GLES 3.1; }
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { QOpenGLContext::currentContext()->extraFunctions()->glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
void glDispatchComputeIndirect(GLintptr indirect) { QOpenGLContext::currentContext()->extraFunctions()->glDispatchComputeIndirect(indirect); }
void glDrawArraysIndirect(GLenum mode, const void *indirect) { QOpenGLContext::currentContext()->extraFunctions()->glDrawArraysIndirect(mode, indirect); }
void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) { QOpenGLContext::currentContext()->extraFunctions()->glDrawElementsIndirect(mode, type, indirect); }
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { QOpenGLContext::currentContext()->extraFunctions()->glFramebufferParameteri(target, pname, param); }
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetFramebufferParameteriv(target, pname, params); }
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramInterfaceiv(program, programInterface, pname, params); }
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramResourceIndex(program, programInterface, name); }
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params); }
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramResourceLocation(program, programInterface, name); }
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glUseProgramStages(pipeline, stages, program); }
void glActiveShaderProgram(GLuint pipeline, GLuint program) { QOpenGLContext::currentContext()->extraFunctions()->glActiveShaderProgram(pipeline, program); }
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) { QOpenGLContext::currentContext()->extraFunctions()->glCreateShaderProgramv(type, count, strings); }
void glBindProgramPipeline(GLuint pipeline) { QOpenGLContext::currentContext()->extraFunctions()->glBindProgramPipeline(pipeline); }
void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { QOpenGLContext::currentContext()->extraFunctions()->glDeleteProgramPipelines(n, pipelines); }
void glGenProgramPipelines(GLsizei n, GLuint *pipelines) { QOpenGLContext::currentContext()->extraFunctions()->glGenProgramPipelines(n, pipelines); }
GLboolean glIsProgramPipeline(GLuint pipeline) { QOpenGLContext::currentContext()->extraFunctions()->glIsProgramPipeline(pipeline); }
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramPipelineiv(pipeline, pname, params); }
void glProgramUniform1i(GLuint program, GLint location, GLint v0) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1i(program, location, v0); }
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2i(program, location, v0, v1); }
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3i(program, location, v0, v1, v2); }
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4i(program, location, v0, v1, v2, v3); }
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1ui(program, location, v0); }
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2ui(program, location, v0, v1); }
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3ui(program, location, v0, v1, v2); }
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4ui(program, location, v0, v1, v2, v3); }
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1f(program, location, v0); }
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2f(program, location, v0, v1); }
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3f(program, location, v0, v1, v2); }
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4f(program, location, v0, v1, v2, v3); }
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1iv(program, location, count, value); }
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2iv(program, location, count, value); }
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3iv(program, location, count, value); }
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4iv(program, location, count, value); }
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1uiv(program, location, count, value); }
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2uiv(program, location, count, value); }
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3uiv(program, location, count, value); }
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4uiv(program, location, count, value); }
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform1fv(program, location, count, value); }
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform2fv(program, location, count, value); }
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform3fv(program, location, count, value); }
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniform4fv(program, location, count, value); }
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix3fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { QOpenGLContext::currentContext()->extraFunctions()->glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
void glValidateProgramPipeline(GLuint pipeline) { QOpenGLContext::currentContext()->extraFunctions()->glValidateProgramPipeline(pipeline); }
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { QOpenGLContext::currentContext()->extraFunctions()->glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { QOpenGLContext::currentContext()->extraFunctions()->glBindImageTexture(unit, texture, level, layered, layer, access, format); }
void glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) { QOpenGLContext::currentContext()->extraFunctions()->glGetBooleani_v(target, index, data); }
void glMemoryBarrier(GLbitfield barriers) { QOpenGLContext::currentContext()->extraFunctions()->glMemoryBarrier(barriers); }
void glMemoryBarrierByRegion(GLbitfield barriers) { QOpenGLContext::currentContext()->extraFunctions()->glMemoryBarrierByRegion(barriers); }
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { QOpenGLContext::currentContext()->extraFunctions()->glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { QOpenGLContext::currentContext()->extraFunctions()->glGetMultisamplefv(pname, index, val); }
void glSampleMaski(GLuint maskNumber, GLbitfield mask) { QOpenGLContext::currentContext()->extraFunctions()->glSampleMaski(maskNumber, mask); }
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetTexLevelParameteriv(target, level, pname, params); }
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { QOpenGLContext::currentContext()->extraFunctions()->glGetTexLevelParameterfv(target, level, pname, params); }
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { QOpenGLContext::currentContext()->extraFunctions()->glBindVertexBuffer(bindingindex, buffer, offset, stride); }
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { QOpenGLContext::currentContext()->extraFunctions()->glVertexAttribBinding(attribindex, bindingindex); }
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { QOpenGLContext::currentContext()->extraFunctions()->glVertexBindingDivisor(bindingindex, divisor); }
