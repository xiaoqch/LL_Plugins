#pragma once
#include <EventAPI.h>
#include <RegCommandAPI.h>

// llstruct help
// llstruct list [Location]
// llstruct load name [pos] [Location]
// llstruct save Location name pos1 [pos2]
// llstruct copy fromLocation name toLocation [name]
// llstruct delete name Location

class LLStructureCommand :
    public Command
{
    enum class Operation {
        Help,
        List,
        Load,
        Save,
        Import,
        Export,
        Delete,
    } operation;
    enum class Location {
        File,
        Level,
        Memory,
    } location1, location2;
    CommandPosition commandPos1, commandPos2;
    string name, nameOpt;
    bool name_isSet, commandPos_isSet, location_isSet;
    virtual void execute(class CommandOrigin const&, class CommandOutput&) const override;
public:
    static void setup(CommandRegistry& registry);
};

