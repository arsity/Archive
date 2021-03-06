/*
 * File: set.h
 * -----------
 * This file exports the <code>Set</code> class, which implements a
 * collection for storing a set of distinct elements.
 * 
 * @version 2019/02/04
 * - changed internal implementation to wrap std collections
 * @version 2018/03/19
 * - added constructors that accept a comparison function
 * @version 2018/03/10
 * - added methods front, back
 * @version 2016/12/09
 * - added iterator version checking support (implicitly via Map)
 * @version 2016/12/06
 * - slight speedup bug fix in equals() method
 * @version 2016/09/24
 * - refactored to use collections.h utility functions
 * @version 2016/08/11
 * - added containsAll, isSupersetOf methods
 * @version 2016/08/10
 * - added support for std initializer_list usage, such as {1, 2, 3}
 *   in constructor, addAll, containsAll, isSubsetOf, isSupersetOf, removeAll,
 *   retainAll, and operators +, +=, -, -=, *, *=
 * @version 2016/08/04
 * - fixed operator >> to not throw errors
 * @version 2015/07/05
 * - using global hashing functions rather than global variables
 * @version 2014/11/13
 * - added comparison operators <, >=, etc.
 * - added template hashCode function
 * @version 2014/10/10
 * - removed use of __foreach macro
 */

#include "private/init.h"   // ensure that Stanford C++ lib is initialized

#ifndef INTERNAL_INCLUDE
#include "private/initstudent.h"   // insert necessary included code by student
#endif // INTERNAL_INCLUDE

#ifndef _set_h
#define _set_h

#include <initializer_list>
#include <iostream>
#include <set>
#include <functional>
#include <type_traits>

#define INTERNAL_INCLUDE 1
#include "collections.h"
#define INTERNAL_INCLUDE 1
#include "map.h"
#undef INTERNAL_INCLUDE

/* Traits type for the Set, which wraps an underlying Map. */
namespace stanfordcpplib {
namespace collections {
template<typename T>
struct SetTraits {
  using ValueType = T;
  using MapType = Map<T, bool>;
  static std::string name() {
    return "Set";
  }

  /* The Set type does allow you to construct the underlying Map by handing
   * along a std::function.
   */
  template<typename Function>
  static MapType construct(Function comparator) {
    static_assert(std::is_assignable < std::function < bool(
    const ValueType &, const ValueType &)>, Function > ::value,
        "Oops! Seems like you tried to initialize a Set incorrectly. Click here for details.");
    /*
     * Hello student! If you are reading this message, it means that you tried to
     * initialize a Set improperly. For example, you might have tried to write
     * something like this:
     *
     *     Set<int> mySet = 137; // Oops!
     *
     * Here, for example, you're trying to assign an int to a Set<int>.
     *
     * or perhaps you had a function like this one:
     *
     *     void myFunction(Set<int>& mySet);
     *
     * and you called it by writing
     *
     *     myFunction(someSet + someOtherSet); // Oops!
     *     myFunction({ });                    // Oops!
     *
     * In these cases, you're trying to pass a value into a function that takes
     * its argument by (non-const) reference. C++ doesn't allow you to do this.
     *
     * To see where the actual error comes from, look in the list of error messages
     * in Qt Creator. You should see a line that says "required from here" that
     * points somewhere in your code. That's the actual line you wrote that caused
     * the problem, so double-click on that error message and see where it takes
     * you. Now you know where to look!
     *
     * Hope this helps!
     */
    return MapType(comparator);
  }

  /* You can also default-construct it. */
  static MapType construct() {
    return {};
  }

  /* However, you can't pass in any other arguments. */
  template<typename... Args>
  static void construct(MapType &, Args &&...) {
    static_assert(Fail<Args...>::value,
                  "Oops! Seems like you tried to initialize a Set incorrectly. Click here for details.");

    /*
     * Hello student! If you are reading this message, it means that you tried to
     * initialize a Set improperly. For example, you might have tried to write
     * something like this:
     *
     *     Set<int> mySet = 137; // Oops!
     *
     * Here, for example, you're trying to assign an int to a Set<int>.
     *
     * or perhaps you had a function like this one:
     *
     *     void myFunction(Set<int>& mySet);
     *
     * and you called it by writing
     *
     *     myFunction(someSet + someOtherSet); // Oops!
     *     myFunction({ });                    // Oops!
     *
     * In these cases, you're trying to pass a value into a function that takes
     * its argument by (non-const) reference. C++ doesn't allow you to do this.
     *
     * To see where the actual error comes from, look in the list of error messages
     * in Qt Creator. You should see a line that says "required from here" that
     * points somewhere in your code. That's the actual line you wrote that caused
     * the problem, so double-click on that error message and see where it takes
     * you. Now you know where to look!
     *
     * Hope this helps!
     */
    error("static_assert failed?");
  }
};
}
}

/*
 * A set of elements stored in sorted order. The elements must be comparable
 * using the < operator in order to be stored here.
 */
template<typename ValueType>
using Set = stanfordcpplib::collections::GenericSet<stanfordcpplib::collections::SetTraits<ValueType>>;

#endif // _set_h
