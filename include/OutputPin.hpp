#ifndef GPIO_OUTPUTPIN_HPP
#define GPIO_OUTPUTPIN_HPP

#include <Prerequisites.hpp>

#include <cstdint>

namespace gpio
{
	class GPIO_API OutputPin
	{
		public:
			OutputPin() = delete;
			OutputPin(std::uint8_t pin);
			OutputPin(const OutputPin&) = delete;
			OutputPin(OutputPin&&) = delete;

			~OutputPin() = default;

			inline std::uint8_t GetPin() const;

			inline void On();
			inline void Off();

			void SetValue(bool value);

			OutputPin& operator=(const OutputPin&) = delete;
			OutputPin& operator=(OutputPin&&) = delete;

		private:

			std::uint8_t m_pin;
	};
}

#include <OutputPin.inl>

#endif // !GPIO_OUTPUTPIN_HPP
