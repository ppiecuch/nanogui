#include <nanogui/shader.h>

NAMESPACE_BEGIN(nanogui)

size_t data_type_size(DataType type) {

    switch (type) {
        case DataType::UInt8:
        case DataType::Int8:
        case DataType::Bool:
            return 1;

        case DataType::UInt16:
        case DataType::Int16:
        case DataType::Float16:
            return 2;

        case DataType::UInt32:
        case DataType::Int32:
        case DataType::Float32:
            return 4;

        case DataType::UInt64:
        case DataType::Int64:
        case DataType::Float64:
            return 8;

        default:
            throw std::runtime_error("Unknown type!");
    }
}

const char *data_type_name(DataType type) {
    switch (type) {
        case DataType::Bool:    return "bool";
        case DataType::UInt8:   return "uint8";
        case DataType::Int8:    return "int8";
        case DataType::UInt16:  return "uint16";
        case DataType::Int16:   return "int16";
        case DataType::UInt32:  return "uint32";
        case DataType::Int32:   return "int32";
        case DataType::UInt64:  return "uint64";
        case DataType::Int64:   return "int64";
        case DataType::Float16: return "float16";
        case DataType::Float32: return "float32";
        case DataType::Float64: return "float64";
        default:
            throw std::runtime_error("Unknown type!");
    }
}

std::string Shader::Buffer::to_string() const {
    std::string result = "Buffer[type=";
    switch (type) {
        case BufferType::VertexBuffer: result += "vertex"; break;
        case BufferType::FragmentBuffer: result += "fragment"; break;
        case BufferType::UniformBuffer: result += "uniform"; break;
        case BufferType::IndexBuffer: result += "index"; break;
        default: result += "unknown"; break;
    }
    result += ", dtype=";
    result += data_type_name(dtype);
    result += ", shape=[";
    for (size_t i = 0; i < ndim; ++i) {
        result += std::to_string(shape[i]);
        if (i + 1 < ndim)
            result += ", ";
    }
    result += "]]";
    return result;
}

NAMESPACE_END(nanogui)
