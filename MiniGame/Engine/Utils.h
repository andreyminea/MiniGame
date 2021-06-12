#pragma once
#include <string>
#include <SFML/Window/Keyboard.hpp>

namespace Engine
{
	namespace Utils
	{
		class Keyboard
		{
		public:
			static std::string GetStringKey(sf::Keyboard::Key key);
		};
	}
}

