#ifndef GPIO_PREREQUISITES_HPP
#define GPIO_PREREQUISITES_HPP

#define GPIO_IMPORT __declspec(dllimport)
#define GPIO_EXPORT __declspec(dllexport)

#ifdef GPIO_BUILD
	#define GPIO_API __attribute__((visibility ("default")))
#else
	#define GPIO_API __attribute__((visibility ("default")))
#endif // GPIO_BUILD


#endif // !GPIO_PREREQUISITES_HPP