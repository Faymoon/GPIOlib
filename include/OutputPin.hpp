#ifndef GPIO_OUTPUTPIN_HPP
#define GPIO_OUTPUTPIN_HPP

#include <Prerequisites.hpp>
#include <Pin.hpp>

#include <cstdint>
#include <ofstream>

namespace gpio
{
	class GPIO_API OutputPin : public Pin
	{
		public:
			OutputPin(std::uint8_t pin);

			inline void On();
			inline void Off();

			void SetValue(bool value);

		private:

			std::ofstream m_outFile;
	};
}

#include <OutputPin.inl>

#endif // !GPIO_OUTPUTPIN_HPP
