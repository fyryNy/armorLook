// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
		Array<Armor> Menu::GetArmors() {
				Array<Armor> armors;
				auto c_item = parser->GetIndex(oCItem::classDef->scriptClassName);
				for (int i = 0; i < parser->symtab.GetNumInList(); i++) {
						zCPar_Symbol* symbol = parser->symtab.table[i];

						if (i == parser->instance_help) {
								continue;
						}

						if (symbol->type != zPAR_TYPE_INSTANCE) {
								continue;
						}

						//  Instance isn't global scope
						if (symbol->name.HasWord(".")) {
								continue;
						}
						auto baseClass = parser->GetBaseClass(symbol);
						if (baseClass != c_item) {
								continue;
						}
						oCItem* item = static_cast<oCItem*>(ogame->GetGameWorld()->CreateVob(zVOB_TYPE_ITEM, i));

						if (item->mainflag != ITM_CAT_ARMOR || item->wear != ITM_WEAR_TORSO || item->name.IsEmpty() || item->GetVisualChange().IsEmpty() || item->GetVisualChange().StartWith("SRN_") || item->GetVisualChange().StartWith("AML_"))
						{
								zRELEASE(item);
								continue;
						}

						Armor arm;
						arm.Name = (string)item->name;
						arm.VisualName = (string)item->GetVisualChange();
						arm.VisualSkin = item->visual_skin;
						armors.Insert(arm);

						zRELEASE(item);
				}
				return armors;
		};

}