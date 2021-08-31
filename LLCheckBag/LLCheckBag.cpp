#include "pch.h"
#include "FormHelper.h"

void onPlayerSelected(std::string response) {
	std::cout << response << std::endl;
}

bool oncmd_checkBag(CommandOrigin const& ori, CommandOutput& outp) {
	std::cout << ori.getName()<< std::endl;
	//if (ori.getOriginType() != OriginType::Player) {
	//	outp.addMessage("此指令仅允许由玩家执行");
	//	return false;
	//}
	Player* player = (Player*)ori.getEntity();
	sendPlayerList(player, {""}, onPlayerSelected);
	return true;
}

void regListener() {
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("llcb", "查询在线离线玩家背包数据", 1);  //注册指令
		CmdOverload(llcb, oncmd_checkBag);  //重载指令
		});
}

void entry() {
	regListener();
	std::cout << "[LLCheckBag] 在线离线玩家查包插件已加载，版本：v1.0" << std::endl;
}