/*
    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/**
 * \file nanogui/common.h
 *
 * \brief Common definitions used by NanoGUI.
 */

#pragma once

#if defined(WITH_ENOKI_LIB)
# include <enoki/array.h>
# include <enoki/transform.h>
#elif defined(WITH_EIGEN_LIB)
# include <Eigen/Core>
#else
# ifndef WITH_LINALG_LIB
#  define WITH_LINALG_LIB
# endif
# include <algebra/linalg.h>
# include <algebra/c++.h>
#endif
#include <stdint.h>
#include <array>
#include <vector>
#include <functional>

#ifdef QT_GUI_LIB
# include <qnamespace.h>
#endif

/* Set to 1 to draw boxes around widgets */
//#define NANOGUI_SHOW_WIDGET_BOUNDS 1

#if !defined(NAMESPACE_BEGIN) || defined(DOXYGEN_DOCUMENTATION_BUILD)
    /**
     * \brief Convenience macro for namespace declarations
     *
     * The macro ``NAMESPACE_BEGIN(nanogui)`` will expand to ``namespace
     * nanogui {``. This is done to hide the namespace scope from editors and
     * C++ code formatting tools that may otherwise indent the entire file.
     * The corresponding ``NAMESPACE_END`` macro also lists the namespace
     * name for improved readability.
     *
     * \param name
     *     The name of the namespace scope to open
     */
    #define NAMESPACE_BEGIN(name) namespace name {
#endif
#if !defined(NAMESPACE_END) || defined(DOXYGEN_DOCUMENTATION_BUILD)
    /**
     * \brief Convenience macro for namespace declarations
     *
     * Closes a namespace (counterpart to ``NAMESPACE_BEGIN``)
     * ``NAMESPACE_END(nanogui)`` will expand to only ``}``.
     *
     * \param name
     *     The name of the namespace scope to close
     */
    #define NAMESPACE_END(name) }
#endif

#if defined(NANOGUI_SHARED)
#  if defined(_WIN32)
#    if defined(NANOGUI_BUILD)
#      define NANOGUI_EXPORT __declspec(dllexport)
#    else
#      define NANOGUI_EXPORT __declspec(dllimport)
#    endif
#  elif defined(NANOGUI_BUILD)
#    define NANOGUI_EXPORT __attribute__ ((visibility("default")))
#  else
#    define NANOGUI_EXPORT
#  endif
#else
     /**
      * If the build flag ``NANOGUI_SHARED`` is defined, this directive will expand
      * to be the platform specific shared library import / export command depending
      * on the compilation stage.  If undefined, it expands to nothing. **Do not**
      * define this directive on your own.
      */
#    define NANOGUI_EXPORT
#endif

/* Force usage of discrete GPU on laptops (macro must be invoked in main application) */
#if defined(_WIN32) && !defined(DOXYGEN_DOCUMENTATION_BUILD)
#define NANOGUI_FORCE_DISCRETE_GPU() \
    extern "C" { \
        __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1; \
        __declspec(dllexport) int NvOptimusEnablement = 1; \
    }
#else
/**
 * On Windows, exports ``AmdPowerXpressRequestHighPerformance`` and
 * ``NvOptimusEnablement`` as ``1``.
 */
#define NANOGUI_FORCE_DISCRETE_GPU()
#endif

#if defined(_WIN32)
#  if defined(NANOGUI_BUILD)
/* Quench a few warnings on when compiling NanoGUI on Windows */
#    pragma warning(disable : 4127) // warning C4127: conditional expression is constant
#    pragma warning(disable : 4244) // warning C4244: conversion from X to Y, possible loss of data
#  endif
#  pragma warning(disable : 4251) // warning C4251: class X needs to have dll-interface to be used by clients of class Y
#  pragma warning(disable : 4714) // warning C4714: function X marked as __forceinline not inlined
#endif

// These will produce broken links in the docs build
#if !defined(DOXYGEN_SHOULD_SKIP_THIS)

extern "C" {
    /* Opaque handle types */
    typedef struct NVGcontext NVGcontext;
    typedef struct GLFWwindow GLFWwindow;
};

struct NVGcolor;
struct NVGglyphPosition;
struct GLFWcursor;

#endif // DOXYGEN_SHOULD_SKIP_THIS

#ifdef QT_GUI_LIB

 enum NguiFlag {
    NGUI_MOUSE_BUTTON_1 = 1,
    NGUI_MOUSE_BUTTON_LEFT = NGUI_MOUSE_BUTTON_1,
    NGUI_MOUSE_BUTTON_2 = 2,
    NGUI_MOUSE_BUTTON_RIGHT = NGUI_MOUSE_BUTTON_2,
    NGUI_MOUSE_BUTTON_3 = 4,
    NGUI_MOUSE_BUTTON_MIDDLE = NGUI_MOUSE_BUTTON_3,
    NGUI_KEY_ESCAPE = Qt::Key_Escape,
    NGUI_KEY_LEFT = Qt::Key_Left,
    NGUI_KEY_RIGHT = Qt::Key_Right,
    NGUI_KEY_UP = Qt::Key_Up,
    NGUI_KEY_DOWN = Qt::Key_Down,
    NGUI_KEY_HOME = Qt::Key_Home,
    NGUI_KEY_END = Qt::Key_End,
    NGUI_KEY_BACKSPACE = Qt::Key_Backspace,
    NGUI_KEY_DELETE = Qt::Key_Delete,
    NGUI_KEY_ENTER = Qt::Key_Enter,
    NGUI_KEY_A = Qt::Key_A,
    NGUI_KEY_X = Qt::Key_X,
    NGUI_KEY_C = Qt::Key_C,
    NGUI_KEY_V = Qt::Key_V,
    NGUI_KEY_R = Qt::Key_R,
    NGUI_MOD_SHIFT,
    NGUI_MOD_CONTROL,
    NGUI_MOD_SUPER,
    NGUI_SYSTEM_COMMAND_MOD,
    NGUI_PRESS = 0,
    NGUI_RELEASE = 1,
    NGUI_REPEAT = 2
 };

#else

 enum NguiFlag {
    NGUI_MOUSE_BUTTON_1 = GLFW_MOUSE_BUTTON_1,
    NGUI_MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT,
    NGUI_MOUSE_BUTTON_2 = GLFW_MOUSE_BUTTON_2,
    NGUI_MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
    NGUI_MOUSE_BUTTON_3 = GLFW_MOUSE_BUTTON_3,
    NGUI_MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
    NGUI_KEY_ESCAPE = GLFW_KEY_ESCAPE,
    NGUI_KEY_LEFT = GLFW_KEY_LEFT,
    NGUI_KEY_RIGHT = GLFW_KEY_RIGHT,
    NGUI_KEY_UP = GLFW_KEY_UP,
    NGUI_KEY_DOWN = GLFW_KEY_DOWN,
    NGUI_KEY_HOME = GLFW_KEY_HOME,
    NGUI_KEY_END = GLFW_KEY_END,
    NGUI_KEY_BACKSPACE = GLFW_KEY_BACKSPACE,
    NGUI_KEY_DELETE = GLFW_KEY_DELETE,
    NGUI_KEY_ENTER = GLFW_KEY_ENTER,
    NGUI_KEY_A = GLFW_KEY_A,
    NGUI_KEY_X = GLFW_KEY_X,
    NGUI_KEY_C = GLFW_KEY_C,
    NGUI_KEY_V = GLFW_KEY_V,
    NGUI_KEY_R = GLFW_KEY_R = GLFW_KEY_R,
    NGUI_MOD_SHIFT = GLFW_KEY_SHIFT,
    NGUI_MOD_CONTROL = GLFW_KEY_CONTROL,
    NGUI_MOD_SUPER = GLFW_KEY_SUPER,
    NGUI_SYSTEM_COMMAND_MOD = GLFW_SYSTEM_COMMAND_MOD,
    NGUI_PRESS = GLFW_PRESS,
    NGUI_RELEASE = GLFW_RELEASE,
    NGUI_REPEAT = GLFW_REPEAT
 };

#endif

// Define command key for windows/mac/linux
#if defined(__APPLE__) || defined(DOXYGEN_DOCUMENTATION_BUILD)
    /// If on OSX, maps to ``NGUI_MOD_SUPER``.  Otherwise, maps to ``NGUI_MOD_CONTROL``.
    #define SYSTEM_COMMAND_MOD NGUI_MOD_SUPER
#else
    #define SYSTEM_COMMAND_MOD NGUI_MOD_CONTROL
#endif

#ifdef QT_GUI_LIB
    double sysGetTime();
#else
    #define sysGetTime glfwGetTime
#endif

NAMESPACE_BEGIN(nanogui)

/// Common data formats for images/textures
enum class DataType : uint8_t {
    // Signed and unsigned integer formats
#if defined(WITH_ENOKI_LIB)
    Invalid = (uint8_t) enoki::EnokiType::Invalid,

    Bool    = (uint8_t) enoki::EnokiType::Bool,
    UInt8   = (uint8_t) enoki::EnokiType::UInt8,
    Int8    = (uint8_t) enoki::EnokiType::Int8,
    UInt16  = (uint8_t) enoki::EnokiType::UInt16,
    Int16   = (uint8_t) enoki::EnokiType::Int16,
    UInt32  = (uint8_t) enoki::EnokiType::UInt32,
    Int32   = (uint8_t) enoki::EnokiType::Int32,
    UInt64  = (uint8_t) enoki::EnokiType::UInt64,
    Int64   = (uint8_t) enoki::EnokiType::Int64,

    // Floating point formats
    Float16 = (uint8_t) enoki::EnokiType::Float16,
    Float32 = (uint8_t) enoki::EnokiType::Float32,
    Float64 = (uint8_t) enoki::EnokiType::Float64
#else
    Invalid,

    Bool,
    UInt8,
    Int8,
    UInt16,
    Int16,
    UInt32,
    Int32,
    UInt64,
    Int64,

    // Floating point formats
    Float16,
    Float32,
    Float64
#endif
};

/// Cursor shapes available to use in GLFW/Qt.  Shape of actual cursor determined by Operating System.
enum class Cursor {
    Arrow = 0,  ///< The arrow cursor.
    IBeam,      ///< The I-beam cursor.
    Crosshair,  ///< The crosshair cursor.
    Hand,       ///< The hand cursor.
    HResize,    ///< The horizontal resize cursor.
    VResize,    ///< The vertical resize cursor.
    CursorCount ///< Not a cursor --- should always be last: enables a loop over the cursor types.
};

/* Import some common vector types */
#if defined(WITH_ENOKI_LIB)
 using Vector2f     = enoki::Array<float, 2>;
 using Vector3f     = enoki::Array<float, 3>;
 using Vector4f     = enoki::Array<float, 4>;
 using Vector2i     = enoki::Array<int32_t, 2>;
 using Vector3i     = enoki::Array<int32_t, 3>;
 using Vector4i     = enoki::Array<int32_t, 4>;
 using Matrix2f     = enoki::Matrix<float, 2>;
 using Matrix3f     = enoki::Matrix<float, 3>;
 using Matrix4f     = enoki::Matrix<float, 4>;
 using Quaternion4f = enoki::Quaternion<float>;

 namespace nutils {
    template<typename T> constexpr size_t array_depth_v = enoki::array_depth_v<T>;
    template<typename T> constexpr DataType array_type_v = static_cast<DataType>(enoki::enoki_type_v<enoki::scalar_t<T>>);

    template<typename T> bool all(const T &v) { return enoki::all(v); }
    template<typename T> bool contains(const T &v, const T &lower_bound, const T &upper_bound) { return enoki::all(v >= lower_bound) && enoki::all(v < upper_bound); }

    template<typename T> auto abs(const T &v) { return enoki::abs(v); }
    template<typename T> enoki::scalar_t<T> dot(const T &a, const T &b) { return enoki::dot(a, b); }
    template<typename T> T cross(const T &a, const T &b) { return enoki::cross(a, b); }
    template<typename T> T normalize(const T &v) { return enoki::normalize(v); }
    template<typename T> enoki::scalar_t<T> norm(const T &v) { return enoki::norm(v); }
    template<typename T> auto squared_norm(const T &v) { return enoki::squared_norm(v); }
    template<typename V> auto sincos(const V &v) { return enoki::sincos(v); }
    template<typename T> enoki::scalar_t<T> hmax(const T &v) { return enoki::hmax(v); }
    template<typename T> enoki::scalar_t<T> hmin(const T &v) { return enoki::hmin(v); }

    template<typename T> const T identity() { return enoki::identity<T>(); }

    template <typename Matrix, typename Vector> Matrix translate(const Vector &v) { return enoki::translate<Matrix>(v); }
    template <typename Matrix, typename Vector> Matrix scale(const Vector &v) { return enoki::scale<Matrix>(v); }
    template <typename Matrix, typename Vector3> Matrix rotate(const Vector3 &axis, const enoki::entry_t<Matrix> &angle) { return enoki::rotate<Matrix>(axis, angle); }

    template <typename Quat, typename Vector3> Quat rotate(const Vector3 &axis, const enoki::value_t<Quat> &angle) { return enoki::rotate<Quat>(axis, angle); }
    template<typename Matrix, typename Quat> Matrix quat_to_matrix(const Quat &q) { return enoki::quat_to_matrix<Matrix>(q); }

    template <typename Matrix> Matrix ortho(const enoki::entry_t<Matrix> &left, const enoki::entry_t<Matrix> &right,
                                            const enoki::entry_t<Matrix> &bottom, const enoki::entry_t<Matrix> &top,
                                            const enoki::entry_t<Matrix> &near_, const enoki::entry_t<Matrix> &far_) {
        return enoki::ortho<Matrix>(left, right, bottom, top, near_, far_); }
    template <typename Matrix> Matrix perspective(const enoki::entry_t<Matrix> &fov,
                                                  const enoki::entry_t<Matrix> &near_, const enoki::entry_t<Matrix> &far_,
                                                  const enoki::entry_t<Matrix> &aspect = 1.f) {
        return enoki::perspective<Matrix>(fov, near_, far_, aspect); }
    template <typename Matrix, typename Point, typename Vector> Matrix look_at(const Point &origin, const Point &target, const Vector &up) {
        return enoki::look_at<Matrix>(origin, target, up); }
 }
#elif defined(WITH_EIGEN_LIB)
 using Vector2f = Eigen::Vector2f;
 using Vector3f = Eigen::Vector3f;
 using Vector4f = Eigen::Vector4f;
 using Vector2i = Eigen::Vector2i;
 using Vector3i = Eigen::Vector3i;
 using Vector4i = Eigen::Vector4i;
 using Matrix3f = Eigen::Matrix3f;
 using Matrix4f = Eigen::Matrix4f;
 using VectorXf = Eigen::VectorXf;
 using MatrixXf = Eigen::MatrixXf;

 using MatrixXu = Eigen::Matrix<uint32_t, Eigen::Dynamic, Eigen::Dynamic>;

 namespace nutils {
    template<typename T> bool all(const T &v) { return all(v); }
    template<typename T> bool contains(const T &v, const T &lower_bound, const T &upper_bound) {
        auto d = v.array(); return (d >= lower_bound).all() && (d < upper_bound.array()).all(); }
 }
#else // WITH_LINALG_LIB
# define DATA_INFO(dt, ds) \
    constexpr static const DataType data_type = DataType::dt; \
    constexpr static const int data_depth = ds
 struct Vector2f;
 struct Vector2i : linalg::aliases::int2 {
     typedef int entry_type;
     typedef linalg::aliases::int2 base_type;
     Vector2i(int a = 0) : base_type(a, a) {}
     Vector2i(int x, int y) : base_type(x, y) {}
     Vector2i(base_type v) : base_type(v) {}
     explicit Vector2i(const Vector2f &v);
     int &x() { return base_type::x; }
     int &y() { return base_type::y; }
     int x() const { return base_type::x; }
     int y() const { return base_type::y; }
     int &width() { return base_type::x; }
     int &height() { return base_type::y; }
     int width() const { return base_type::x; }
     int height() const { return base_type::y; }
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     DATA_INFO(Int32, 1);
 };
 using Vector3i     = linalg::aliases::int3;
 using Vector4i     = linalg::aliases::int4;
 struct Vector2f : linalg::aliases::float2 {
     typedef float entry_type;
     typedef linalg::aliases::float2 base_type;
     Vector2f(float a) : base_type(a, a) {}
     Vector2f(float x, float y) : base_type(x, y) {}
     Vector2f(base_type v) : base_type(v) {}
     Vector2f(const Vector2i &v) : base_type(v) {}
     float &x() { return base_type::x; }
     float &y() { return linalg::aliases::float2::y; }
     float x() const { return base_type::x; }
     float y() const { return base_type::y; }
     float &width() { return base_type::x; }
     float &height() { return base_type::y; }
     float width() const { return base_type::x; }
     float height() const { return base_type::y; }
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     const Vector2i &toVector2i() const { return Vector2i(base_type::x, base_type::y); }
     DATA_INFO(Float32, 1);
 };
 struct Vector3f : linalg::aliases::float3 {
     typedef float entry_type;
     typedef linalg::aliases::float3 base_type;
     explicit Vector3f(float a) : base_type(a, a, a) {}
     Vector3f(float x, float y, float z) : base_type(x, y, z) {}
     Vector3f(base_type v) : base_type(v) {}
     Vector3f(const Vector3i &v) : base_type(v) {}
     float &x() { return base_type::x; }
     float &y() { return base_type::y; }
     float &z() { return base_type::z; }
     float x() const { return base_type::x; }
     float y() const { return base_type::y; }
     float z() const { return base_type::z; }
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     DATA_INFO(Float32, 1);
 };
 struct Vector4f : linalg::aliases::float4 {
     typedef float entry_type;
     typedef linalg::aliases::float4 base_type;
     explicit Vector4f(float a) : base_type(a, a, a, a) {}
     Vector4f(float x, float y, float z, float w) : base_type(x, y, z, w) {}
     Vector4f(base_type v) : base_type(v) {}
     Vector4f(const Vector4i &v) : base_type(v) {}
     float &x() { return base_type::x; }
     float &y() { return base_type::y; }
     float &z() { return base_type::z; }
     float &w() { return base_type::w; }
     float x() const { return base_type::x; }
     float y() const { return base_type::y; }
     float z() const { return base_type::z; }
     float w() const { return base_type::w; }
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     DATA_INFO(Float32, 1);
 };
 using Matrix2f     = linalg::aliases::float2x2;
 using Matrix3f     = linalg::aliases::float3x3;
 struct Matrix4f : linalg::aliases::float4x4 {
     typedef float entry_type;
     typedef linalg::aliases::float4x4 base_type;
     Matrix4f() : base_type() {}
     Matrix4f(const Vector4f & x_, const Vector4f & y_, const Vector4f & z_, const Vector4f & w_) : base_type(x_, y_, z_, w_) {}
     Matrix4f(base_type v) : base_type(v) {}
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     DATA_INFO(Float32, 2);
 };
 struct Quaternion4f : linalg::aliases::float4 {
     typedef float entry_type;
     typedef linalg::aliases::float4 base_type;
     Quaternion4f() : base_type() {}
     Quaternion4f(float a) : base_type(a, a, a, a) {}
     Quaternion4f(base_type v) : base_type(v) {}
     const base_type &base() const { return *static_cast<const base_type*>(this); }
     DATA_INFO(Float32, 1);
 };

 inline Vector2i::Vector2i(const Vector2f &v) : base_type(v) {}

 static bool operator == (const Vector2i& a, const Vector2i& b) { return linalg::compare(a.base(), b.base()) == 0; }
 static bool operator != (const Vector2i& a, const Vector2i& b) { return linalg::compare(a.base(), b.base()) != 0; }
 static bool operator != (const Vector4f& a, const Vector4f& b) { return linalg::compare(a.base(), b.base()) != 0; }
 static bool operator < (const Vector2i& a, const Vector2i& b) { return linalg::compare(a.base(), b.base()) < 0; }
 static bool operator < (const Vector2f& a, const Vector2f& b) { return linalg::compare(a.base(), b.base()) < 0; }
 static bool operator > (const Vector3f& a, const float b) { return linalg::compare(a.base(), linalg::aliases::float3(b)) > 0; }
 static bool operator >= (const Vector2i& a, const int b) { return linalg::compare(a.base(), linalg::aliases::int2(b)) >= 0; }
 static bool operator >= (const Vector2f& a, const Vector2f& b) { return linalg::compare(a.base(), b.base()) >= 0; }
 static bool operator >= (const Vector2f& a, const int b) { return linalg::compare(a.base(), linalg::aliases::float2(b)) >= 0; }
 static Vector2i operator - (const Vector2i& v) { return linalg::apply(linalg::detail::op_neg{}, v.base()); }
 static Vector3f operator - (const Vector3f& v) { return linalg::apply(linalg::detail::op_neg{}, v.base()); }
 static Vector2i operator + (const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b.base()); }
 static Vector2f operator + (const Vector2f& a, const Vector2f& b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b.base()); }
 static Vector3f operator + (const Vector3f& a, float b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b); }
 static Vector3f operator + (const Vector3f& a, const Vector3f& b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b.base()); }
 static Vector4f operator + (const Vector4f& a, float b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b); }
 static Vector4f operator + (const Vector4f& a, const Vector4f& b) { return linalg::apply(linalg::detail::op_add{}, a.base(), b.base()); }
 static Vector2f operator * (const Vector2i& a, float b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b); }
 static Vector2i operator * (const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b.base()); }
 static Vector2f operator * (const Vector2f& a, const Vector2f& b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b.base()); }
 static Vector3f operator * (const Vector3f& a, float b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b); }
 static Vector3f operator * (const Vector3f& a, const Vector3f& b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b.base()); }
 static Vector4f operator * (const Vector4f& a, float b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b); }
 static Matrix4f operator * (const Matrix4f& a, const Matrix4f& b) { return linalg::mul(a.base(), b.base()); }
 static Quaternion4f operator * (const Quaternion4f& a, const Quaternion4f& b) { return linalg::apply(linalg::detail::op_mul{}, a.base(), b.base()); }
 static Vector2f operator - (const Vector2f& a, const Vector2f& b) { return linalg::apply(linalg::detail::op_sub{}, a.base(), b.base()); }
 static Vector2i operator - (const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::op_sub{}, a.base(), b.base()); }
 static Vector3f operator - (const Vector3f& a, const Vector3f& b) { return linalg::apply(linalg::detail::op_sub{}, a.base(), b.base()); }
 static Vector2i operator / (const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b.base()); }
 static Vector2f operator / (const Vector2f& a, const Vector2f& b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b.base()); }
 static Vector3f operator / (const Vector3f& a, float b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b); }
 static Vector3f operator / (const Vector3f& a, const Vector3f& b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b.base()); }
 static Vector4f operator / (const Vector4f& a, float b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b); }
 static Vector4f operator / (const Vector4f& a, const Vector4f& b) { return linalg::apply(linalg::detail::op_div{}, a.base(), b.base()); }
 static Vector2i max(const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::max{}, a.base(), b.base()); }
 static Vector2i min(const Vector2i& a, const Vector2i& b) { return linalg::apply(linalg::detail::min{}, a.base(), b.base()); }
 namespace nutils {
    template <typename Array> using entry_t = typename Array::entry_type; // Value trait to access the entry type of a array
    template <typename Matrix> using column_t = typename Matrix::V;       // Value trait to access the column type of a matrix

    template <typename T> constexpr size_t array_depth_v = T::data_depth;
    template <> constexpr size_t array_depth_v<float> = 0;
    template <typename T> constexpr DataType array_type_v = T::data_type;
    template <> constexpr DataType array_type_v<float> = DataType::Float32;

    static inline bool all(const bool &v) { return v; }
    template<typename T> bool contains(const T &v, const T &lower_bound, const T &upper_bound) {
        return ( linalg::all(gequal(v.base(),lower_bound.base())) && linalg::all(linalg::less(v.base(),upper_bound.base())) ); }

    template<typename T> T max(const T &a, const T &b) { return linalg::max(a.base(), b.base()); }
    template<typename T> T min(const T &a, const T &b) { return linalg::min(a.base(), b.base()); }
    template<typename T> entry_t<T> hmax(const T &v) { return linalg::maxelem(v.base()); }
    template<typename T> entry_t<T> hmin(const T &v) { return linalg::minelem(v.base()); }

    template<typename T> T abs(const T &v) { return linalg::abs(v.base()); }
    template<typename T> entry_t<T> dot(const T &a, const T &b) { return linalg::dot(a, b); }
    template<typename T> T cross(const T &a, const T &b) { return linalg::cross(a.base(), b.base()); }
    template<typename T> T normalize(const T &v) { return linalg::normalize(v.base()); }
    template<typename T> float norm(const T &v) { return linalg::sqrt(linalg::dot(v.base(), v.base())); }
    template<typename T> entry_t<T> squared_norm(const T &v) { return linalg::dot(v.base(), v.base()); }
    template<typename V> auto sincos(const V &v) { return std::make_pair(std::sin(v), std::cos(v)); }

    template <typename T> T identity() { return T(linalg::identity); }

    template <typename Matrix> Matrix diag(const column_t<Matrix> &value) {
        Matrix result;
        for (size_t i = 0; i < Matrix::size(); ++i)
            result[i][i] = value[i];
        return result;
    }
    template <typename Matrix, typename Vector> Matrix translate(const Vector &v) { return linalg::translation_matrix(v); }
    template <typename Matrix, typename Vector> Matrix scale(const Vector &v) { return linalg::scaling_matrix(v); }
    template <typename Matrix, typename Vector3> Matrix rotate(const Vector3 &axis, const entry_t<Matrix> &angle) {
        using Column = column_t<Matrix>;
        using Value = entry_t<Matrix>;

        Value sin_theta = sin(angle),
            cos_theta = cos(angle),
            cos_theta_m = 1.f - cos_theta;

        Vector3 shuf1 = Vector3(axis.y(), axis.z(), axis.x()),
            shuf2 = Vector3(axis.z(), axis.x(), axis.y()),
            tmp0  = axis * axis * cos_theta_m + cos_theta,
            tmp1  = axis * shuf1 * cos_theta_m + shuf2 * sin_theta,
            tmp2  = axis * shuf2 * cos_theta_m - shuf1 * sin_theta;

        return Matrix(
            Column(tmp0.x(), tmp1.x(), tmp2.x(), 0.f),
            Column(tmp2.y(), tmp0.y(), tmp1.y(), 0.f),
            Column(tmp1.z(), tmp2.z(), tmp0.z(), 0.f),
            Column(0.f, 0.f, 0.f, 1.f)
        );
    }

    inline entry_t<Quaternion4f> abs(const Quaternion4f &q) { return norm(q); }
# ifdef COMMON_COMPILATION_UNIT
    template<> Quaternion4f rotate(const Vector3f &axis, const entry_t<Quaternion4f> &angle) { return linalg::rotation_quat(axis, angle); }
# else
    template<> Quaternion4f rotate(const Vector3f &axis, const entry_t<Quaternion4f> &angle);
# endif
    template<typename M> M quat_to_matrix(const Quaternion4f &q) { return linalg::rotation_matrix(q); }

    template <typename Matrix> Matrix ortho(const entry_t<Matrix> &left, const entry_t<Matrix> &right,
                                            const entry_t<Matrix> &bottom, const entry_t<Matrix> &top,
                                            const entry_t<Matrix> &n, const entry_t<Matrix> &f) {
        return linalg::orthographic_matrix(left, right, bottom, top, n, f, linalg::pos_z);
    }
    template <typename Matrix> Matrix perspective(const entry_t<Matrix> &fov,
                                                  const entry_t<Matrix> &n, const entry_t<Matrix> &f,
                                                  const entry_t<Matrix> &aspect = 1.f) {
        return linalg::perspective_matrix(fov, aspect, n, f, linalg::pos_z);
    }
    template<typename Matrix, typename Point, typename Vector> Matrix look_at(const Point &origin, const Point &target, const Vector &up) {
        auto dir = normalize(target - origin);
        auto left = normalize(cross(dir, up));
        auto new_up = cross(left, dir);

        using Scalar = entry_t<Matrix>;

        return Matrix(
            column_t<Matrix>({left, Scalar(0)}),
            column_t<Matrix>({new_up, Scalar(0)}),
            column_t<Matrix>({-dir, Scalar(0)}),
            column_t<Matrix>(
                -dot(left, origin),
                -dot(new_up, origin),
                dot(dir, origin),
                1.f
            )
        );
    }
 }
#endif


/**
 * \class Color common.h nanogui/common.h
 *
 * \brief Stores an RGBA floating point color value.
 *
 * This class simply wraps around an ``Vector4f``, providing some convenient
 * methods and terminology for thinking of it as a color.  The data operates in the
 * same way as ``Vector4f``, and the following values are identical:
 *
 * \rst
 * +---------+-------------+-----------------------+-------------+
 * | Channel | Array Index | enoki Vector4f Value  | Color Value |
 * +=========+=============+=======================+=============+
 * | Red     | ``0``       | x()                   | r()         |
 * +---------+-------------+-----------------------+-------------+
 * | Green   | ``1``       | y()                   | g()         |
 * +---------+-------------+-----------------------+-------------+
 * | Blue    | ``2``       | z()                   | b()         |
 * +---------+-------------+-----------------------+-------------+
 * | Alpha   | ``3``       | w()                   | w()         |
 * +---------+-------------+-----------------------+-------------+
 *
 * .. note::
 *    The method for the alpha component is **always** ``w()``.
 * \endrst
 */
class Color : public Vector4f {
public:
    using Vector4f::Vector4f;

    /// Default constructor: represents black (``r, g, b, a = 0``)
    Color() : Color(0, 0, 0, 0) { }

    /// Initialize from a 4D vector
    Color(const Vector4f &color) : Vector4f(color) { }

    /**
     * Copies (x, y, z) from the input vector, and uses the value specified by
     * the ``alpha`` parameter for this Color object's alpha component.
     *
     * \param color
     * The three dimensional float vector being copied.
     *
     * \param alpha
     * The value to set this object's alpha component to.
     */
    Color(const Vector3f &color, float alpha)
        : Color(color[0], color[1], color[2], alpha) { }

    /**
     * Copies (x, y, z) from the input vector, casted as floats first and then
     * divided by ``255.0``, and uses the value specified by the ``alpha``
     * parameter, casted to a float and divided by ``255.0`` as well, for this
     * Color object's alpha component.
     *
     * \param color
     * The three dimensional integer vector being copied, will be divided by ``255.0``.
     *
     * \param alpha
     * The value to set this object's alpha component to, will be divided by ``255.0``.
     */
    Color(const Vector3i &color, int alpha)
        : Color(Vector3f(color) / 255.f, alpha / 255.f) { }

    /**
     * Copies (x, y, z) from the input vector, and sets the alpha of this color
     * to be ``1.0``.
     *
     * \param color
     * The three dimensional float vector being copied.
     */
    Color(const Vector3f &color) : Color(color, 1.0f) {}

    /**
     * Copies (x, y, z) from the input vector, casting to floats and dividing by
     * ``255.0``.  The alpha of this color will be set to ``1.0``.
     *
     * \param color
     * The three dimensional integer vector being copied, will be divided by ``255.0``.
     */
    Color(const Vector3i &color)
        : Color(Vector3f(color) / 255.f, 1.f) { }

    /**
     * Copies (x, y, z, w) from the input vector, casting to floats and dividing
     * by ``255.0``.
     *
     * \param color
     * The three dimensional integer vector being copied, will be divided by ``255.0``.
     */
    Color(const Vector4i &color)
        : Color(Vector4f(color) / 255.f) { }

    /**
     * Creates the Color ``(intensity, intensity, intensity, alpha)``.
     *
     * \param intensity
     * The value to be used for red, green, and blue.
     *
     * \param alpha
     * The alpha component of the color.
     */
    Color(float intensity, float alpha)
        : Color(Vector3f(intensity), alpha) { }

    /**
     * Creates the Color ``(intensity, intensity, intensity, alpha) / 255.0``.
     * Values are casted to floats before division.
     *
     * \param intensity
     * The value to be used for red, green, and blue, will be divided by ``255.0``.
     *
     * \param alpha
     * The alpha component of the color, will be divided by ``255.0``.
     */
    Color(int intensity, int alpha)
        : Color(Vector3i(intensity), alpha) { }

    /**
     * Explicit constructor: creates the Color ``(r, g, b, a)``.
     *
     * \param r
     * The red component of the color.
     *
     * \param g
     * The green component of the color.
     *
     * \param b
     * The blue component of the color.
     *
     * \param a
     * The alpha component of the color.
     */
    Color(float r, float g, float b, float a) : Color(Vector4f(r, g, b, a)) { }

    /**
     * Explicit constructor: creates the Color ``(r, g, b, a) / 255.0``.
     * Values are casted to floats before division.
     *
     * \param r
     * The red component of the color, will be divided by ``255.0``.
     *
     * \param g
     * The green component of the color, will be divided by ``255.0``.
     *
     * \param b
     * The blue component of the color, will be divided by ``255.0``.
     *
     * \param a
     * The alpha component of the color, will be divided by ``255.0``.
     */
    Color(int r, int g, int b, int a) : Color(Vector4f((float) r, (float) g, (float) b, (float) a) / 255.f) { }

    /// Return a reference to the red channel
    float &r() { return x(); }
    /// Return a reference to the red channel (const version)
    const float &r() const { return x(); }
    /// Return a reference to the green channel
    float &g() { return y(); }
    /// Return a reference to the green channel (const version)
    const float &g() const { return y(); }
    /// Return a reference to the blue channel
    float &b() { return z(); }
    /// Return a reference to the blue channel (const version)
    const float &b() const { return z(); }

    /**
     * Computes the luminance as ``l = 0.299r + 0.587g + 0.144b + 0.0a``.  If
     * the luminance is less than 0.5, white is returned.  If the luminance is
     * greater than or equal to 0.5, black is returned.  Both returns will have
     * an alpha component of 1.0.
     */
    Color contrasting_color() const {
        float luminance = nutils::dot(*this, Color(0.299f, 0.587f, 0.144f, 0.f));
        return Color(luminance < 0.5f ? 1.f : 0.f, 1.f);
    }

    /// Allows for conversion between this Color and NanoVG's representation.
    inline operator const NVGcolor &() const;

# ifdef DATA_INFO
    DATA_INFO(Float32, 1);
# endif
};

// skip the forward declarations for the docs
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* Forward declarations */
template <typename T> class ref;
class AdvancedGridLayout;
class BoxLayout;
class Button;
class CheckBox;
class Canvas;
class ColorWheel;
class ColorPicker;
class ComboBox;
class GLFramebuffer;
class GLShader;
class GridLayout;
class GroupLayout;
class ImagePanel;
class ImageView;
class Label;
class Layout;
class MessageDialog;
class Object;
class Popup;
class PopupButton;
class ProgressBar;
class RenderPass;
class Shader;
class Screen;
class Serializer;
class Slider;
class TabWidgetBase;
class TabWidget;
class TextBox;
class TextArea;
class Texture;
class Theme;
class ToolButton;
class VScrollPanel;
class Widget;
class Window;

#endif // DOXYGEN_SHOULD_SKIP_THIS

/**
 * Static initialization; should be called once before invoking **any** NanoGUI
 * functions **if** you are having NanoGUI manage OpenGL / GLFW.  This method
 * is effectively a wrapper call to ``glfwInit()``, so if you are managing
 * OpenGL / GLFW on your own *do not call this method*.
 *
 * \rst
 * Refer to :ref:`nanogui_example_3` for how you might go about managing OpenGL
 * and GLFW on your own, while still using NanoGUI's classes.
 * \endrst
 */
extern NANOGUI_EXPORT void init();

/// Static shutdown; should be called before the application terminates.
extern NANOGUI_EXPORT void shutdown();

/**
 * \brief Enter the application main loop
 *
 * \param refresh
 *     NanoGUI issues a redraw call whenever an keyboard/mouse/.. event is
 *     received. In the absence of any external events, it enforces a redraw
 *     once every ``refresh`` milliseconds. To disable the refresh timer,
 *     specify a negative value here.
 *
 * \param detach
 *     This parameter only exists in the Python bindings. When the active
 *     \c Screen instance is provided via the \c detach parameter, the
 *     ``mainloop()`` function becomes non-blocking and returns
 *     immediately (in this case, the main loop runs in parallel on a newly
 *     created thread). This feature is convenient for prototyping user
 *     interfaces on an interactive Python command prompt. When
 *     ``detach != None``, the function returns an opaque handle that
 *     will release any resources allocated by the created thread when the
 *     handle's ``join()`` method is invoked (or when it is garbage
 *     collected).
 *
 * \remark
 *     Unfortunately, Mac OS X strictly requires all event processing to take
 *     place on the application's main thread, which is fundamentally
 *     incompatible with this type of approach. Thus, NanoGUI relies on a
 *     rather crazy workaround on Mac OS (kudos to Dmitriy Morozov):
 *     ``mainloop()`` launches a new thread as before but then uses
 *     libcoro to swap the thread execution environment (stack, registers, ..)
 *     with the main thread. This means that the main application thread is
 *     hijacked and processes events in the main loop to satisfy the
 *     requirements on Mac OS, while the thread that actually returns from this
 *     function is the newly created one (paradoxical, as that may seem).
 *     Deleting or ``join()``ing the returned handle causes application to
 *     wait for the termination of the main loop and then swap the two thread
 *     environments back into their initial configuration.
 */
extern NANOGUI_EXPORT void mainloop(float refresh = -1.f);

/// Request the application main loop to terminate (e.g. if you detached mainloop).
extern NANOGUI_EXPORT void leave();

/// Return whether or not a main loop is currently active
extern NANOGUI_EXPORT bool active();

/**
 * \brief Enqueue a function to be executed executed before
 * the application is redrawn the next time.
 *
 * NanoGUI is not thread-safe, and async() provides a mechanism
 * for queuing up UI-related state changes from other threads.
 */
extern NANOGUI_EXPORT void async(const std::function<void()> &func);

/**
 * \brief Open a native file open/save dialog.
 *
 * \param filetypes
 *     Pairs of permissible formats with descriptions like
 *     ``("png", "Portable Network Graphics")``.
 *
 * \param save
 *     Set to ``true`` if you would like subsequent file dialogs to open
 *     at whatever folder they were in when they close this one.
 */
extern NANOGUI_EXPORT std::string
file_dialog(const std::vector<std::pair<std::string, std::string>> &filetypes,
            bool save);

/**
 * \brief Open a native file open dialog, which allows multiple selection.
 *
 * \param filetypes
 *     Pairs of permissible formats with descriptions like
 *     ``("png", "Portable Network Graphics")``.
 *
 * \param save
 *     Set to ``true`` if you would like subsequent file dialogs to open
 *     at whatever folder they were in when they close this one.
 *
 * \param multiple
 *     Set to ``true`` if you would like to be able to select multiple
 *     files at once. May not be simultaneously true with \p save.
 */
extern NANOGUI_EXPORT std::vector<std::string>
file_dialog(const std::vector<std::pair<std::string, std::string>> &filetypes,
            bool save, bool multiple);

#if defined(__APPLE__) || defined(DOXYGEN_DOCUMENTATION_BUILD)
/**
 * \brief Move to the application bundle's parent directory
 *
 * This is function is convenient when deploying .app bundles on OSX. It
 * adjusts the file path to the parent directory containing the bundle.
 */
extern NANOGUI_EXPORT void chdir_to_bundle_parent();
#endif

/**
 * \brief Convert a single UTF32 character code to UTF8.
 *
 * \rst
 * NanoGUI uses this to convert the icon character codes
 * defined in :ref:`file_nanogui_entypo.h`.
 * \endrst
 *
 * \param c
 *     The UTF32 character to be converted.
 */
extern NANOGUI_EXPORT std::array<char, 8> utf8(int c);

/// Load a directory of PNG images and upload them to the GPU (suitable for use with ImagePanel)
extern NANOGUI_EXPORT std::vector<std::pair<int, std::string>>
    load_image_directory(NVGcontext *ctx, const std::string &path);

/// Convenience function for instanting a PNG icon from the application's data segment (via bin2c)
#define nvgImageIcon(ctx, name) nanogui::__nanogui_get_image(ctx, #name, name##_png, name##_png_size)
/// Helper function used by nvg_image_icon
extern NANOGUI_EXPORT int __nanogui_get_image(NVGcontext *ctx, const std::string &name,
                                              uint8_t *data, uint32_t size);

NAMESPACE_END(nanogui)
