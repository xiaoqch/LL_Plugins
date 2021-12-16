#pragma once
#include <RegCommandAPI.h>

class TemplateCommand :
    public Command
{
    string param;
    virtual void execute(class CommandOrigin const&, class CommandOutput&) const override;
public:
    static void setup(CommandRegistry& registry);
};

