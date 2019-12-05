
#include <OutputPin.hpp>

namespace gpio
{
	inline void OutputPin::On()
	{
		SetValue(true);
	}

	inline void OutputPin::Off()
	{
		SetValue(false);
	}
}