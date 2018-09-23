#ifndef GPIO_DEVICE_HPP
#define GPIO_DEVICE_HPP

#include <Prerequisites.hpp>

#include <cstdint>
#include <unordered_map>
#include <fstream>

namespace gpio
{
	class GPIO_API Device
	{
		friend class InputPin;
		friend class OutputPin;

		public:
			Device();
			Device(const Device&) = delete;
			Device(Device&&) = delete;

			~Device();

			Device& operator=(const Device&) = delete;
			Device& operator=(Device&&) = delete;

		private:

			static Device* instance;

			enum class PinMode : bool
			{
				Input,
				Output
			};

			void RegisterPin(std::uint8_t pin, PinMode mode);

			bool ReadPinValue(std::uint8_t pin);

			void WritePinValue(std::uint8_t pin, bool value);

			std::unordered_map<std::uint8_t, std::ofstream> m_outPins;
			std::unordered_map<std::uint8_t, std::ifstream> m_inPins;

			std::ofstream m_exportFile;
	};
}

#endif // !GPIO_DEVICE_HPP
