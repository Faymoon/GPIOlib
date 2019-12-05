
#include <OutputPin.hpp>

#include <string>
#include <fstream>

namespace gpio
{
	OutputPin::OutputPin(std::uint8_t pin)
		:
		Pin(pin)
	{
		std::ofstream directionFile("/sys/class/gpio/gpio" + std::to_string(m_pin) + "/direction");
		directionFile << "out";

		m_outFile = std::ofstream("/sys/class/gpio/gpio" + std::to_string(m_pin) + "/value");
	}


	void OutputPin::SetValue(bool value)
	{
		m_outFile << (value ? '1' : '0');
	}
}