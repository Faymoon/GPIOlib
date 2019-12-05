
#include <InputPin.hpp>

#include <fstream>
#include <string>

namespace gpio
{
	InputPin::InputPin(std::uint8_t pin)
		:
		Pin(pin)
	{
		std::ofstream directionFile("/sys/class/gpio/gpio" + std::to_string(m_pin) + "/direction");
		directionFile << "in";

		m_inFile = std::ifstream("/sys/class/gpio/gpio" + std::to_string(m_pin) + "/value");
	}

	bool InputPin::ReadValue() const
	{
		char c;
		m_inFile >> c;
		m_inFile.seekg(0);

		return c == '1' ? true : false ;
	}
}