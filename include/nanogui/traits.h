/*
    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

#include <nanogui/common.h>

/// c++ compatibility utilities
namespace std {
#ifdef CPP17
    template<typename A, typename B> constexpr bool is_same_type = std::is_same_v<A, B>;
    template<typename T> constexpr bool is_scalar_type = std::is_scalar_v<T>;
    template<typename T> constexpr bool is_integral_type = std::is_integral_v<T>;
    template<typename T> constexpr bool is_floating_point_type = std::is_floating_point_v<T>;
    template<typename T> constexpr bool is_signed_type = std::is_signed_v<T>;
#else
    template<typename A, typename B> constexpr bool is_same_type = std::is_same<A, B>::value;
    template<typename T> constexpr bool is_scalar_type = std::is_scalar<T>::value;
    template<typename T> constexpr bool is_integral_type = std::is_integral<T>::value;
    template<typename T> constexpr bool is_floating_point_type = std::is_floating_point<T>::value;
    template<typename T> constexpr bool is_signed_type = std::is_signed<T>::value;
#endif
}

NAMESPACE_BEGIN(nanogui)

/// Listing of various field types that can be used as variables in shaders
enum class VariableType {
    Invalid = 0,
    Int8,
    UInt8,
    Int16,
    UInt16,
    Int32,
    UInt32,
    Int64,
    UInt64,
    Float16,
    Float32,
    Float64,
    Bool
};

/// Convert from a C++ type to an element of \ref VariableType
template <typename T> constexpr VariableType get_type() {
    if constexpr (std::is_same_type<T, bool>)
        return VariableType::Bool;

    if constexpr (std::is_integral_type<T>) {
        if constexpr (sizeof(T) == 1)
            return std::is_signed_type<T> ? VariableType::Int8 : VariableType::UInt8;
        else if constexpr (sizeof(T) == 2)
            return std::is_signed_type<T> ? VariableType::Int16 : VariableType::UInt16;
        else if constexpr (sizeof(T) == 4)
            return std::is_signed_type<T> ? VariableType::Int32 : VariableType::UInt32;
        else if constexpr (sizeof(T) == 8)
            return std::is_signed_type<T> ? VariableType::Int64 : VariableType::UInt64;
    } else if constexpr (std::is_floating_point_type<T>) {
        if constexpr (sizeof(T) == 2)
            return VariableType::Float16;
        else if constexpr (sizeof(T) == 4)
            return VariableType::Float32;
        else if constexpr (sizeof(T) == 8)
            return VariableType::Float64;
    }

    return VariableType::Invalid;
}

/// Return the size in bytes associated with a specific variable type
extern NANOGUI_EXPORT size_t type_size(VariableType type);

/// Return the name (e.g. "uint8") associated with a specific variable type
extern NANOGUI_EXPORT const char *type_name(VariableType type);

namespace detail {
    template <template <typename...> typename B, typename T>
    struct is_base_of_impl {
    private:
        template <typename... Ts>
        static constexpr std::true_type test(const B<Ts...> *);
        static constexpr std::false_type test(...);

    public:
        using type = decltype(test(std::declval<T *>()));
    };
}

/// Check if 'T' is a subtype of a given template 'B'
template <template <typename...> typename B, typename T>
using is_base_of = typename detail::is_base_of_impl<B, T>::type;

template <template <typename...> typename B, typename T>
constexpr bool is_base_of_v = is_base_of<B, T>::value;

template <typename T>
constexpr bool is_enoki_array_v =
    nanogui::is_base_of_v<enoki::ArrayBase, std::decay_t<T>>;

template <typename T>
constexpr bool is_nanogui_array_v =
    std::is_base_of<nanogui::ArrayBase, std::decay_t<T>>();

template <typename T>
constexpr bool is_nanogui_matrix_v =
    std::is_base_of<nanogui::MatrixBase, std::decay_t<T>>();

NAMESPACE_END(nanogui)
