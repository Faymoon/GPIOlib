#ifndef GPIO_INPUTPIN_HPP
#define GPIO_INPUTPIN_HPP

#include <Prerequisites.hpp>

#include <cstdint>

namespace gpio
{
	class GPIO_API InputPin
	{
		public:
			InputPin() = delete;
			InputPin(std::uint8_t pin);
			InputPin(const InputPin&) = delete;
			InputPin(InputPin&&) = delete;

			~InputPin() = default;

			inline std::uint8_t GetPin() const;

			bool ReadValue() const;

			InputPin& operator=(const InputPin&) = delete;
			InputPin& operator=(InputPin&&) = delete;

		private:

			std::uint8_t m_pin;
	};
}

#include <InputPin.inl>

#endif // !GPIO_INPUTPIN_HPP
