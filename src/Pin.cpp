
#include <Pin.hpp>

#include <string>
#include <fstream>

namespace gpio
{
	Pin::Pin(std::uint8_t pin)
		:
		m_pin(pin)
	{
		std::ofstream exportFile("/sys/class/gpio/export");
		exportFile << std::to_string(m_pin);
	}

	Pin::~Pin()
	{
		std::ofstream unexportFile("/sys/class/gpio/unexport");
		unexportFile << std::to_string(m_pin);
	}
}