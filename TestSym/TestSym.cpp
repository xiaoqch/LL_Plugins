#include "pch.h"
#include "loader/Loader.h"
#include "mc/Actor.h"
#include "mc/BlockSource.h"
#include "mc/LevelChunk.h"
#include "SymHelper.h"
#include "mc/Command.h"
#include "mc/CommandReg.h"
#include "api/regCommandHelper.h"
#include "api/basicEvent.h"
#include <iostream>
#include <string>

using namespace std;

bool oncmd_tsym(CommandOrigin const& ori, CommandOutput& outp) {
	outp.addMessage("<"+ ori.getName() +"> tsym");
	return true;
}

void regCmd() {
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("tsym", "test sym", 0);//◊¢≤·÷∏¡Ó
		CmdOverload(tsym, oncmd_tsym);//÷ÿ‘ÿ÷∏¡Ó
		});
}

void entry()
{
	regCmd();
	std::cout << "[TestSym] TestSym Loaded. Version: 1.0" << endl;
}

THook(short, "?pullInItems@HopperComponent@@QEAA_NAEAVActor@@@Z", void* a1, Actor* at)
{
	short result = original(a1, at);
	return result;
	if (result != 0) {
		BlockSource* bs = getBlockSourceByDim(at->getDimensionId());
		Vec3 pos = at->getPos();
		LevelChunk* lc = getChunkByXZ(bs, floor(pos.x / 16), floor(pos.z / 16));
		setChunkUnsaved(lc);
	}
	return result;
}