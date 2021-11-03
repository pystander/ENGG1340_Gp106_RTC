#include <type_traits>

// In english: T is instanceof Base
// inline affects the compiler
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}