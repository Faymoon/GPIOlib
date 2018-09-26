
#include <Device.hpp>

#include <cassert>
#include <string>
#include <limits>

namespace gpio
{
	Device::Device()
		:
		m_exportFile("/sys/class/gpio/export")
	{
		m_exportFile.setf(std::ios::unitbuf);

		assert(instance == nullptr && "There should be only one instance of Device");

		instance = this;
	}

	Device::~Device()
	{
		std::ofstream unexportFile("/sys/class/gpio/unexport");
		unexportFile.setf(std::ios::unitbuf);

		for (auto& pin : m_inPins)
		{
			auto pinString = std::to_string(pin.first);

			unexportFile.write(pinString.data(), pinString.size());
		}

		for (auto& pin : m_outPins)
		{
			auto pinString = std::to_string(pin.first);

			unexportFile.write(pinString.data(), pinString.size());
		}
	}

	void Device::RegisterPin(std::uint8_t pin, PinMode mode)
	{
		auto inIterator = m_inPins.find(pin);
		auto outIterator = m_outPins.find(pin);

		auto pinString = std::to_string(pin);

		if (inIterator == m_inPins.end() && outIterator == m_outPins.end())
			m_exportFile.write(pinString.c_str(), pinString.size());

		switch (mode)
		{
			case PinMode::Input:
				if (outIterator != m_outPins.end())
					m_outPins.erase(outIterator);

				if (inIterator == m_inPins.end())
				{
					m_inPins.emplace(pin, "/sys/class/gpio/gpio" + pinString + "/value");

					std::ofstream pinDirectionFile("/sys/class/gpio/gpio" + pinString + "/direction");
					pinDirectionFile.write("in", 2);
				}


				break;
			case PinMode::Output:
				if (inIterator != m_inPins.end())
					m_inPins.erase(inIterator);

				if (outIterator == m_outPins.end())
				{
					m_outPins.emplace(pin, "/sys/class/gpio/gpio" + pinString + "/value");

					std::ofstream pinDirectionFile("/sys/class/gpio/gpio" + pinString + "/direction");
					pinDirectionFile.write("out", 3);
				}

				break;
		}
	}

	bool Device::ReadPinValue(std::uint8_t pin)
	{
		auto& file = m_inPins.find(pin)->second;
		
		file.seekg(0);
		char data = file.get();

		return data == '1' ? true : false;
	}

	void Device::WritePinValue(std::uint8_t pin, bool value)
	{
		auto& file = m_outPins.find(pin)->second;

		file.seekp(0);
		file.put(value ? '1' : '0');
		file.flush();
	}

	Device* Device::instance(nullptr);
}