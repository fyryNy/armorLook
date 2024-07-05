// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
		struct Armor {
				string Name;
				string VisualName;
				int VisualSkin;
		};

		class Menu {
		public:
				Array<Armor> GetArmors();
		};
}