#ifndef GPIO_PIN_HPP
#define GPIO_PIN_HPP

#include <Prerequisites.hpp>

#include <cstdint>

namespace gpio
{
	class GPIO_API Pin
	{
		public:
			Pin() = delete;
			Pin(std::uint8_t pin);
			Pin(const Pin&) = delete;
			Pin(Pin&&) = delete;

			~Pin();

			inline std::uint8_t GetPin() const;

			Pin& operator=(const Pin&) = delete;
			Pin& operator=(Pin&&) = delete;

		protected:

			std::uint8_t m_pin;

	};
}

#include <Pin.inl>

#endif // !GPIO_PIN_HPP
