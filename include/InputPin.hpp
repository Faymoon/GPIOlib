#ifndef GPIO_INPUTPIN_HPP
#define GPIO_INPUTPIN_HPP

#include <Prerequisites.hpp>
#include <Pin.hpp>

#include <cstdint>

namespace gpio
{
	class GPIO_API InputPin : public Pin
	{
		public:
			Pin(std::uint8_t pin);

			bool ReadValue() const;
	};
}

#endif // !GPIO_INPUTPIN_HPP
