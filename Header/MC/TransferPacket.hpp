// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TransferPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TRANSFERPACKET
public:
    class TransferPacket& operator=(class TransferPacket const&) = delete;
    TransferPacket(class TransferPacket const&) = delete;
#endif

public:
    /*0*/ virtual ~TransferPacket();
    /*1*/ virtual int /*enum enum MinecraftPacketIds*/ getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual int /*enum enum StreamReadResult*/ _read(class ReadOnlyBinaryStream&);
    /*
    inline  ~TransferPacket(){
         (TransferPacket::*rv)();
        *((void**)&rv) = dlsym("??1TransferPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI TransferPacket(std::string const&, int);
    MCAPI TransferPacket();

protected:

private:

};