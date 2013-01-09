/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: donator_tele
%Complete: 75
Comment: Donator tele commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"

class donator_tele_commandscript : public CommandScript{

    public:
        donator_tele_commandscript() : CommandScript("donator_tele_commandscript") { }
        
        ChatCommand* GetCommands() const
        {
            static ChatCommand donTeleCommandTable[] =
            {
                { "Orgrimmar",    SEC_DONATOR, false, HandleDonTeleOgCommand,  "Teleports to Orgrimmar",    NULL},
                { "Undercity",    SEC_DONATOR, false, HandleDonTeleUcCommand,  "Teleports to Undercity",    NULL},
                { "Silvermoon",   SEC_DONATOR, false, HandleDonTeleSmCommand,  "Teleports to Silvermoon",   NULL},
                { "Thunderbluff", SEC_DONATOR, false, HandleDonTeleTbCommand,  "Teleports to Thunderbluff", NULL},
                { "Dalaran",      SEC_DONATOR, false, HandleDonTeleDalaCommand,"Teleports to Dalaran",      NULL},
                { "Stormwind",    SEC_DONATOR, false, HandleDonTeleSwCommand   "Teleports to Stormwind",    NULL},
                { "Ironforge",    SEC_DONATOR, false, HandleDonTeleIfCommand,  "Teleports to Ironforge",    NULL},
                { "Darnassus",    SEC_DONATOR, false, HandleDonTeleDsCommand,  "Teleports to Darnassus",    NULL},
                { "Exodar",       SEC_DONATOR, false, HandleDonTeleExCommand,  "Teleports to Exodar",       NULL}


            };


            static ChatCommand donCommandTable[] =
            {
                { "tele",       SEC_DONATOR, false, NULL, "Teleports to a Capital", donTeleCommandTable },
                { NULL,         0,           false, NULL,   "", NULL}


            };

            static ChatCommand commandTable[] =
            {
                { "don",        SEC_DONATOR, false, NULL,   "", donCommandTable },
                { NULL,         0,           false, NULL,           "", NULL    }

            };

            return commandTable;
        };


    static bool HandleDonTeleOgCommand(ChatHandler* handler, const char* args)
    {
        
        Player* player = handler->GetSession()->GetPlayer();

        if(!player->IsPremium())
        {
            
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == ALLIANCE)
        {
            player->MonsterWhisper("You must be in the Team 'Horde' to teleport to Orgrimmar", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo(1,1629.36f,-4373.39f, 31.2564f, 3.54839f);
            return true;

        }

    }

    static bool HandleDonTeleUcCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        if(!player->IsPremium())
        {
            
        return false;    
        }
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == ALLIANCE)
        {
            player->MonsterWhisper("You must be in the Team 'Horde' to teleport to Undercity", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo(0,1584.07f,241.987f, -52.1534f, 0.049647f);
            return true;

        }

    }

    static bool HandleDonTeleSmCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();

        if(!player->IsPremium())
        { 
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == ALLIANCE)
        {
            player->MonsterWhisper("You must be in the Team 'Horde' to teleport to Silvermoon", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo(530,9487.69f,-7279.2f, 14.2866f, 6.16478f);
            return true;

        }

    }

    static bool HandleDonTeleTbCommand(ChatHandler* handler, const char* args)
    {

        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {    
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == ALLIANCE)
        {
            player->MonsterWhisper("You must be in the Team 'Horde' to teleport to Thunderbluff", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo(1 , -1277.37f , 124.804f , 131.287f , 5.22274f);
            return true;

        }

    }

    static bool HandleDonTeleDalaCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {         
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            player->TeleportTo( 571 , 5804.15f , 624.771f , 647.767f , 1.64f );
            return true;

        }

    }

    static bool HandleDonTeleSwCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {   
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == HORDE)
        {
            player->MonsterWhisper("You must be in the Team 'Alliance' to teleport to Stormwind", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo( 0 , -8833.38f , 628.628f , 94.0066f , 1.06535f );
            return true;

        }

    }

    static bool HandleDonTeleIfCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {   
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == HORDE)
        {
            player->MonsterWhisper("You must be in the Team 'Alliance' to teleport to Ironforge", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo( 0 , -4918.88f , -940.406f , 501.564f , 5.42347f );
            return true;

        }

    }

    static bool HandleDonTeleDsCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {   
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == HORDE)
        {
            player->MonsterWhisper("You must be in the Team 'Alliance' to teleport to Darnassus", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo( 1 , 9949.56f , 2284.21f , 1341.4f , 1.59587f );
            return true;

        }

    }


    static bool HandleDonTeleExCommand(ChatHandler* handler, const char* args)
    {


        Player* player = handler->GetSession()->GetPlayer();
        
        if(!player->IsPremium())
        {   
        return false;    
        }
        
        if (player->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player->GetTeam() == HORDE)
        {
            player->MonsterWhisper("You must be in the Team 'Alliance' to teleport to Exodar", player->GetGUID(), true);
            return false;
        }
        else
        {
            player->TeleportTo( 530 , -3965.7f , -11653.6f , -138.844f , 0.852154f );
            return true;

        }
        
    }
};

void AddSC_donator_tele_commandscript()
{
    new donator_tele_commandscript();
}
