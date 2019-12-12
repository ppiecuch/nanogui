//=======================================================================
// Copyright (c) 2013-2016 Baptiste Wicht.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

/*!
 * \file static_if.hpp
 * \brief Contains a C++14 implementation of a poor static if.
 * \brief Contains functions to write to binary files
 * \brief Contains extensions for streams.
 *        The functions must be used with using so that they are considered when compiling.
 * \brief Contains stop watches implementation to measure duration
 */

#ifndef CPP_HPP
#define CPP_HPP

#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iosfwd>


#define cpp_unused(x) ((void)(x))


namespace cpp {


namespace static_if_detail {

/*!
 * \brief Identify functor
 */
struct identity {
    /*!
     * \brief Returns exactly what was passsed as argument
     */
    template <typename T>
    T operator()(T&& x) const {
        return std::forward<T>(x);
    }
};

/*!
 * \brief Helper for static if
 *
 * This base type is when the condition is true
 */
template <bool Cond>
struct statement {
    /*!
     * \brief Execute the if part of the statement
     * \param f The functor to execute
     */
    template <typename F>
    void then(const F& f) {
        f(identity());
    }

    /*!
     * \brief Execute the else part of the statement
     * \param f The functor to execute
     */
    template <typename F>
    void otherwise(const F& f) {
        cpp_unused(f);
    }
};

/*!
 * \brief Helper for static if
 *
 * Specialization for condition is false
 */
template <>
struct statement<false> {
    /*!
     * \brief Execute the if part of the statement
     * \param f The functor to execute
     */
    template <typename F>
    void then(const F& f) {
        cpp_unused(f);
    }

    /*!
     * \brief Execute the else part of the statement
     * \param f The functor to execute
     */
    template <typename F>
    void otherwise(const F& f) {
        f(identity());
    }
};

} //end of namespace static_if_detail

/*!
 * \brief Execute the lambda if the static condition is verified
 *
 * This should be usd to auto lambda to ensure instantiation is only made for
 * the "true" branch
 *
 * \tparam Cond The static condition
 * \param f The lambda to execute if true
 * \return a statement object to execute otherwise if necessary
 */
template <bool Cond, typename F>
static_if_detail::statement<Cond> static_if(F const& f) {
    static_if_detail::statement<Cond> if_;
    if_.then(f);
    return if_;
}




//Binary I/O utility functions

/*!
 * \brief Write the binary representation of the given value
 * \param os The stream to write to
 * \param v The value to write
 */
template <typename T>
void binary_write(std::ostream& os, const T& v) {
    os.write(reinterpret_cast<const char*>(&v), sizeof(v));
}

/*!
 * \brief Write the binary representation of all the given values
 * \param os The stream to write to
 * \param c The container containing the values to write
 */
template <typename Container>
void binary_write_all(std::ostream& os, const Container& c) {
    for (auto& v : c) {
        binary_write(os, v);
    }
}

/*!
 * \brief Load the binary representation of the given value
 * \param is The stream to read from
 * \param v The value to read
 */
template <typename T>
void binary_load(std::istream& is, T& v) {
    is.read(reinterpret_cast<char*>(&v), sizeof(v));
}

/*!
 * \brief Load the binary representation of all the given values
 * \param is The stream to read from
 * \param c The container containing the values to read
 */
template <typename Container>
void binary_load_all(std::istream& is, Container& c) {
    for (auto& v : c) {
        binary_load(is, v);
    }
}




/*!
 * \brief operator<< overload to display the contents of a vector.
 * \param os The output stream
 * \param vec The vector to display
 * \tparam T The value type of the vector
 * \tparam A The allocator type of the vector
 * \return The output stream.
 */
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::vector<T, A>& vec) {
    os << "[";
    std::string comma;
    for (auto& v : vec) {
        os << comma << v;
        comma = ", ";
    }
    os << "]";
    return os;
}

/*!
 * \brief operator<< overload to display the contents of a list.
 * \param os The output stream
 * \param list The list to display
 * \tparam T The value type of the list
 * \tparam A The allocator type of the list
 * \return The output stream.
 */
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::list<T, A>& list) {
    os << "[";
    std::string comma;
    for (auto& v : list) {
        os << comma << v;
        comma = ", ";
    }
    os << "]";
    return os;
}

/*!
 * \brief operator<< overload to display the contents of a deque.
 * \param os The output stream
 * \param deq The deque to display
 * \tparam T The value type of the deque
 * \tparam A The allocator type of the deque
 * \return The output stream.
 */
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::deque<T, A>& deq) {
    os << "[";
    std::string comma;
    for (auto& v : deq) {
        os << comma << v;
        comma = ", ";
    }
    os << "]";
    return os;
}




/*!
 * \brief Default clock type used by the library
 */
using clock_type = std::chrono::high_resolution_clock;

/*!
 * \class stop_watch
 * \brief A stop watch
 * \tparam P The std::chrono precision used by the watch.
 *
 * The watch automatically starts when the constructor is called
 */
template <typename P = std::chrono::milliseconds>
class stop_watch {
public:
    /*!
     * \brief The std::chrono precision used by the watch.
     */
    using precision = P;

    /*!
     * \brief Constructs a new stop_watch and starts it.
     */
    stop_watch() {
        start_point = clock_type::now();
    }

    /*!
     * \brief Return the elapsed time since construction.
     * \return the elapsed time since construction.
     */
    double elapsed() {
        auto end_point = clock_type::now();
        auto time = std::chrono::duration_cast<precision>(end_point - start_point);
        return time.count();
    }

private:
    clock_type::time_point start_point;
};

/*!
 * \class auto_stop_watch
 * \brief An automatic stop watch
 * \tparam P The std::chrono precision used by the watch.
 *
 * The watch automatically starts when the constructor is called and display the duration when destructed.
 */
template <typename P = std::chrono::milliseconds>
class auto_stop_watch {
public:
    /*!
     * \brief The std::chrono precision used by the watch.
     */
    using precision = P;

    /*!
     * \brief Constructs a new auto_stop_watch and starts it.
     * \param title The title that will be displayed when the watch is over.
     */
    explicit auto_stop_watch(std::string title)
            : title(std::move(title)) {
        //Empty
    }

    /*!
     * \brief Destroys the auto_stop_watch and display the elapsed time.
     */
    ~auto_stop_watch() {
        std::cout << title << " took " << watch.elapsed() << std::endl;
    }

private:
    std::string title;
    stop_watch<precision> watch;
};

} //end of namespace cpp

#endif // CPP_HPP
