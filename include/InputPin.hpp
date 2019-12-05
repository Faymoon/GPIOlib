#ifndef GPIO_INPUTPIN_HPP
#define GPIO_INPUTPIN_HPP

#include <Prerequisites.hpp>
#include <Pin.hpp>

#include <cstdint>
#include <fstream>

namespace gpio
{
	class GPIO_API InputPin : public Pin
	{
		public:
			InputPin(std::uint8_t pin);

			bool ReadValue();

		private:

			std::ifstream m_inFile;
	};
}

#endif // !GPIO_INPUTPIN_HPP
