#ifndef GPIO_PREREQUISITES_HPP
#define GPIO_PREREQUISITES_HPP

#define GPIO_IMPORT __attribute__((visibility ("default")))
#define GPIO_EXPORT __attribute__((visibility ("default")))

#ifdef GPIO_BUILD
	#define GPIO_API GPIO_EXPORT
#else
	#define GPIO_API GPIO_IMPORT
#endif // GPIO_BUILD


#endif // !GPIO_PREREQUISITES_HPP