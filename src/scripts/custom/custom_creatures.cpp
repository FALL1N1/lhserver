/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "scriptPCH.h"
#include "custom.h"
#include "ScriptedAI.h"


// TELEPORT NPC

bool GossipHello_TeleportNPC(Player *player, Creature *_Creature)   
{
    // HORDE
    if (player->GetTeam() == HORDE)
    {
        // player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界主城传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 1); // "Major Cities"
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【出生地传送点】|CFF009933 ", GOSSIP_SENDER_MAIN, 3); // "Starting Areas"      
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【初级副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 5); // "Instances"            
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【团队副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 101); // "Raids"                 
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界竞技中心】|CFF009933 ", GOSSIP_SENDER_MAIN, 4015); // "Gurubashi Arena" 
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【卡利姆多区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6010); // "Zones - Kalimdor"    
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【东部王国区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6020); // "Zones - Eastern Kingdoms"    
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【打开个人银行】|CFF009933 ", GOSSIP_SENDER_MAIN, 6030); 
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    // ALLIANCE
    else
    {
        //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界主城传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 2); // "Major Cities"               
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【出生地传送点】|CFF009933 ", GOSSIP_SENDER_MAIN, 4); // "Starting Areas"       
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【初级副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 5); // "Instances"            
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【团队副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 101); // "Raids"                 
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界竞技中心】|CFF009933 ", GOSSIP_SENDER_MAIN, 4015); // "Gurubashi Arena" 
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【卡利姆多区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6010); // "Zones - Kalimdor"     
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【东部王国区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6020); // "Zones - Eastern Kingdoms"     
        player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【打开个人银行】|CFF009933 ", GOSSIP_SENDER_MAIN, 6030); 
		
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    return true;
}

void SendDefaultMenu_TeleportNPC(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1: // Cities [HORDE]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF部落 奥格瑞玛|CFF009933 ", GOSSIP_SENDER_MAIN, 20); // "Orgrimmar"             
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF部落 幽暗城|CFF009933 ", GOSSIP_SENDER_MAIN, 21); // "Undercity"             
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF部落 雷霆崖|CFF009933 ", GOSSIP_SENDER_MAIN, 22); // "Thunderbluff"          
            //player->ADD_GOSSIP_ITEM(5, "Goldshire (Stormwind)" , GOSSIP_SENDER_MAIN, 4018); // 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2: // Cities [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF联盟 暴风城|CFF009933 ", GOSSIP_SENDER_MAIN, 23); // "Stormwind City"        
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF联盟 铁炉堡|CFF009933 ", GOSSIP_SENDER_MAIN, 24); // "Ironforge"             
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF联盟 达纳苏斯|CFF009933 ", GOSSIP_SENDER_MAIN, 25); // "Darnassus"             
            //player->ADD_GOSSIP_ITEM(5, "Razor Hill(Orgrimmar)" , GOSSIP_SENDER_MAIN, 4017);
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3: // Starting Places [HORDE]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF灰影墓穴|CFF009933 ", GOSSIP_SENDER_MAIN, 40); // "Shadow Grave"          
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF试炼谷|CFF009933 ", GOSSIP_SENDER_MAIN, 41); // "Valley of Trials"      
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF纳拉其营地|CFF009933 ", GOSSIP_SENDER_MAIN, 42); // "Camp Narache"          
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 4: // Starting Places [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF北郡山谷|CFF009933 ", GOSSIP_SENDER_MAIN, 43); // "Northshire Valley"     
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF寒脊山谷|CFF009933 ", GOSSIP_SENDER_MAIN, 44); // "Coldridge Valley"      
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF幽影谷|CFF009933 ", GOSSIP_SENDER_MAIN, 45); // "Shadowglen"            
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5: // Instances [PAGE 1]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[22]哀嚎洞穴|CFF009933 ", GOSSIP_SENDER_MAIN, 1249); // "The Wailing Caverns" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[19]死亡矿井|CFF009933 ", GOSSIP_SENDER_MAIN, 1250); // "Deadmines" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[24]影牙城堡|CFF009933 ", GOSSIP_SENDER_MAIN, 1251); // "Shadowfang Keep" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[26]黑暗深渊|CFF009933 ", GOSSIP_SENDER_MAIN, 1252); // "Blackfathom Deeps" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[31]剃刀沼泽|CFF009933 ", GOSSIP_SENDER_MAIN, 1254); // "Razorfen Kraul" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[42]剃刀高地|CFF009933 ", GOSSIP_SENDER_MAIN, 1256); // "Razorfen Downs" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[40]血色修道院|CFF009933 ", GOSSIP_SENDER_MAIN, 1257); // "Scarlet Monastery" 
            player->ADD_GOSSIP_ITEM(7, " |CFF0000FF更多副本|CFF009933 ", GOSSIP_SENDER_MAIN, 5551); // "[More] ->" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5551: // Instances [PAGE 2]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[45]奥达曼|CFF009933 ", GOSSIP_SENDER_MAIN, 1258); // "Uldaman" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[46]祖尔法拉克|CFF009933 ", GOSSIP_SENDER_MAIN, 1259); // "Zul'Farrak" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[49]玛拉顿|CFF009933 ", GOSSIP_SENDER_MAIN, 1260); // "Maraudon" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[53]失落的神庙|CFF009933 ", GOSSIP_SENDER_MAIN, 1261); // "The Sunken Temple" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[57]黑石深渊|CFF009933 ", GOSSIP_SENDER_MAIN, 1262); // "Blackrock Depths" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[60]厄运之槌|CFF009933 ", GOSSIP_SENDER_MAIN, 1263); // "Dire Maul" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[60]黑石塔下|CFF009933 ", GOSSIP_SENDER_MAIN, 1264); // "Blackrock Spire" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[60]斯坦索姆|CFF009933 ", GOSSIP_SENDER_MAIN, 1265); // "Stratholme" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[60]通灵学院|CFF009933 ", GOSSIP_SENDER_MAIN, 1266); // "Scholomance" 
            player->ADD_GOSSIP_ITEM(7, " |CFF0000FF返回 上一级|CFF009933 ", GOSSIP_SENDER_MAIN, 5);  // "<- [Back]" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 101: // Raids
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]祖尔格拉布|CFF009933 ", GOSSIP_SENDER_MAIN, 4000); // "Zul'Gurub" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]奥妮克希亚的巢穴|CFF009933 ", GOSSIP_SENDER_MAIN, 4001); // "Onyxia's Lair" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]熔火之心|CFF009933 ", GOSSIP_SENDER_MAIN, 4002); // "Molten Core" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]黑翼之巢|CFF009933 ", GOSSIP_SENDER_MAIN, 4003); // "Blackwing Lair" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]安其拉废墟|CFF009933 ", GOSSIP_SENDER_MAIN, 4004); // "Ruins of Ahn'Qiraj" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]安其拉神庙|CFF009933 ", GOSSIP_SENDER_MAIN, 4005); // "Temple of Ahn'Qiraj" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF[团]纳克萨玛斯|CFF009933 ", GOSSIP_SENDER_MAIN, 4006); // "Naxxramas" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6010: // Kalimdor
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF灰谷|CFF009933 ", GOSSIP_SENDER_MAIN, 601); // "Ashenvale" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF黑海岸|CFF009933 ", GOSSIP_SENDER_MAIN, 602); // "Darkshore" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF凄凉之地|CFF009933 ", GOSSIP_SENDER_MAIN, 603); // "Desolace" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF杜隆塔尔|CFF009933 ", GOSSIP_SENDER_MAIN, 604); // "Durotar" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF尘泥沼泽|CFF009933 ", GOSSIP_SENDER_MAIN, 605); // "Dustwallow Marsh" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF菲拉斯|CFF009933 ", GOSSIP_SENDER_MAIN, 606); // "Feralas" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF希利苏斯|CFF009933 ", GOSSIP_SENDER_MAIN, 607); // "Silithus" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF石爪山脉|CFF009933 ", GOSSIP_SENDER_MAIN, 608); // "Stonetalon Mountains" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF塔纳利斯|CFF009933 ", GOSSIP_SENDER_MAIN, 609); // "Tanaris" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF贫瘠之地|CFF009933 ", GOSSIP_SENDER_MAIN, 610); // "The Barrens" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF千针石林|CFF009933 ", GOSSIP_SENDER_MAIN, 611); // "Thousand Needles" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF冬泉谷|CFF009933 ", GOSSIP_SENDER_MAIN, 612); // "Winterspring" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6020: // Eastern Kingdoms [PAGE 1]
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF阿拉希高地|CFF009933 ", GOSSIP_SENDER_MAIN, 613); // "Arathi Highlands" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF荒芜之地|CFF009933 ", GOSSIP_SENDER_MAIN, 614); // "Badlands" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF丹莫罗|CFF009933 ", GOSSIP_SENDER_MAIN, 615); // "Dun Morogh" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF暮色森林|CFF009933 ", GOSSIP_SENDER_MAIN, 616); // "Duskwood" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF东瘟疫之地|CFF009933 ", GOSSIP_SENDER_MAIN, 617); // "Eastern Plaguelands" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF艾尔文森林|CFF009933 ", GOSSIP_SENDER_MAIN, 618); // "Elwynn Forest" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF希尔斯布莱德丘陵|CFF009933 ", GOSSIP_SENDER_MAIN, 619); // "Hillsbrad Foothills" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF赤脊山|CFF009933 ", GOSSIP_SENDER_MAIN, 620); // "Redridge Mountains" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF银松森林|CFF009933 ", GOSSIP_SENDER_MAIN, 621); // "Silverpine Forest" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF荆棘谷|CFF009933 ", GOSSIP_SENDER_MAIN, 622); // "Stranglethorn Vale" 
			player->ADD_GOSSIP_ITEM(7, " |CFF0000FF更多|CFF009933 ", GOSSIP_SENDER_MAIN, 5552); // "[More] ->" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"   

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5552: // Eastern Kingdoms [PAGE 2]			
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF悲伤沼泽|CFF009933 ", GOSSIP_SENDER_MAIN, 623); // "Swamp of Sorrows" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF辛特兰|CFF009933 ", GOSSIP_SENDER_MAIN, 624); // "The Hinterlands" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF提瑞斯法林地|CFF009933 ", GOSSIP_SENDER_MAIN, 625); // "Tirisfal Glades" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF西部荒野|CFF009933 ", GOSSIP_SENDER_MAIN, 626); // "Westfall" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF湿地|CFF009933 ", GOSSIP_SENDER_MAIN, 627); // "Wetlands" 
			player->ADD_GOSSIP_ITEM(7, " |CFF0000FF返回 上一级|CFF009933 ", GOSSIP_SENDER_MAIN, 6020);  // "<- [Back]" 
            player->ADD_GOSSIP_ITEM(5, " |CFF0000FF返回 主菜单|CFF009933 ", GOSSIP_SENDER_MAIN, 100); // "<-[Main Menu]"                  

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6030:  // 个人银行
		    player->GetSession()->SendShowBank(player->GetGUID());
            player->CLOSE_GOSSIP_MENU();
                  break;


// ----### CITIES ###----

// ### HORDE ###

        case 20: // Orgrimmar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1437.0f, -4421.0f, 25.24f, 1.65f);
            break;
        case 21: // Undercity
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1822.0999f, 238.638855f, 60.694809f, 0.0f);
            break;
        case 22: // Thunderbluff
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1272.703735f, 116.886490f, 131.016861f, 0.0f);
            break;

// ### ALLIANCE ###

        case 23: // Stormwind
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8828.231445f, 627.927490f, 94.055664f, 0.0f);
            break;
        case 24: // Ironforge
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4917.0f, -955.0f, 502.0f, 0.0f);
            break;
        case 25: // Darnassus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 9962.712891f, 2280.142822f, 1341.394409f, 0.0f);
            break;

// ----### STARTING PLACES ####----

// ### HORDE ###
        case 40: // Shadow Grave
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
            break;
        case 41: // Valley of Trials
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
            break;
        case 42: // Camp Narache
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
            break;

// ### ALLIANCE ###

        case 43: // Nortshire Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
            break;
        case 44: // Coldridge Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
            break;
        case 45: // Shadowglen
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
            break;

// ----### INSTANCES ###----

        case 50: // Dire Maul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3762.340820f, 1216.537598f, 127.434608f, 0.0f);
            break;
        case 51: // Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7528.554688f, -1222.907227f, 285.732941f, 0.0f);
            break;
        case 52: // Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11916.179688f, -1190.977051f, 85.137901f, 0.0f);
            break;
        case 53: // Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4682.391602f, -3709.857422f, 46.792862f, 0.0f);
            break;
        case 54: // Searing Gorge (Moltencore, Blackwinglair)
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7342.270020f, -1096.863892f, 277.06930f, 0.0f);
            break;
        case 55: // Naxxramas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3121.061768f, -3689.973389f, 133.458786f, 0.0f);
            break;
        case 56: // Stratholme Backdoor Entrance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3160.416992f, -4038.750244f, 104.177376f, 0.0f);
            break;
        case 57: // Stratholme Main Entrance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3357.214355f, -3379.713135f, 144.780853f, 0.0f);
            break;
        case 58: // Scholomance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1252.319824f, -2587.151123f, 92.886772f, 0.0f);
            break;

// ---### ZONES ###---

        case 70: // Silithus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7430.070313f, 1002.554565f, 1.249787f, 0.0f);
            break;
        case 71: // Durotar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1006.426819f, -4439.258789f, 11.352882f, 0.0f);
            break;
        case 72: // Ashenvale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1922.842651f, -2169.429688f, 94.327400f, 0.0f);
            break;
        case 73: // Tanaris
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7180.401367f, -3773.328369f, 8.728320f, 0.0f);
            break;
        case 74: // Pretbc Mall
            //player->CLOSE_GOSSIP_MENU();
            //player->TeleportTo(1, 16201.107422f, 16205.1875f, 0.140072f, 1.630427f);
            break;
        case 4015:// Gurubashi
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
            break;
        case 4017:// Razor Hill
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
            break;
        case 4018:// Goldshire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
            break;
        case 1249://teleport player to the Wailing Caverns
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
            break;
        case 1250://teleport player to the Deadmines
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
            break;
        case 1251://teleport player to Shadowfang Keep
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
            break;
        case 1252://teleport player to Blackfathom Deeps
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
            break;
        case 1254://teleport player to Razorfen Kraul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
            break;
        case 1256://teleport player to Razorfen Downs
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
            break;
        case 1257://teleport player to the Scarlet Monastery
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
            break;
        case 1258://teleport player to Uldaman
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
            break;
        case 1259://teleport player to Zul'Farrak
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
            break;
        case 1260://teleport player to Maraudon
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
            break;
        case 1261://teleport player to the Sunken Temple
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
            break;
        case 1262://teleport player to Blackrock Depths
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
            break;
        case 1263://teleport player to Dire Maul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
            break;
        case 1264://teleport player to Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
            break;
        case 1265://teleport player to Stratholme
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
            break;
        case 1266://teleport player to Scholomance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
            break;
        case 4000:// Teleport to Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
            break;
        case 4001:// Teleport to Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
            break;
        case 4002:// Teleport to Molten Core
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
            break;
        case 4003:// Teleport to Blackwing Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
            break;
        case 4004:// Ruins of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
            break;
        case 4005:// Temple of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
            break;
        case 4006:// Naxxramas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(533, 3005.87f, -3435.0f, 293.89f, 0.0f);
            break;
        case 601: // Kalimdor -> Ashenvale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 3469.43f, 847.62f, 6.36476f, 0.0f);
            break;
        case 602: // Kalimdor -> Darkshore
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 6207.5f, -152.833f, 80.8185f, 0.0f);
            break;
        case 603: // Kalimdor -> Desolace
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -93.1614f, 1691.15f, 90.0649f, 0.0f);
            break;
        case 604: // Kalimdor -> Durotar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 341.42f, -4684.7f, 31.9493f, 0.0f);
            break;
        case 605: // Kalimdor -> Duswallow Marsh
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3463.26f, -4123.13f, 18.1043f, 0.0f);
            break;
        case 606: // Kalimdor -> Ferelas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4458.93f, 243.415f, 65.6136f, 0.0f);
            break;
        case 607: // Kalimdor -> Silithus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -6824.15f, 821.273f, 50.6675f, 0.0f);
            break;
        case 608: // Kalimdor -> Stonetalon Mountains
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1145.00f, 85.664f, -6.64f, 0.0f);
            break;
        case 609: // Kalimdor -> Tanaris
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7373.69f, -2950.2f, 11.7598f, 0.0f);
            break;
        case 610: // Kalimdor -> The Barrens
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -456.263f, -2652.7f, 96.615f, 0.0f);
            break;
        case 611: // Kalimdor -> Thousand Needles
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4941.66f, -1595.42f, -33.07f, 0.0f);
            break;
        case 612: // Kalimdor -> Winterspring
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 6107.62f, -4181.6f, 853.322f, 0.0f);
            break;
        case 613: // Eastern Kingdoms -> Arathi Highlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -1544.93f, -2495.01f, 54.11f, 0.0f);
            break;
        case 614: // Eastern Kingdoms -> Badlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6084.95f, -3328.44f, 253.76f, 0.0f);
            break;
        case 615: // Eastern Kingdoms -> Dun Morogh
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -5660.33f, 755.299f, 390.605f, 0.0f);
            break;
        case 616: // Eastern Kingdoms -> Duskwood
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10879.85f, -327.06f, 37.78f, 0.0f);
            break;
        case 617: // Eastern Kingdoms -> Eastern Plaguelands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2280.12f, -5313.16f, 87.74f, 0.0f);
            break;
        case 618: // Eastern Kingdoms -> Elwynn Forest
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9545.78f, -51.81f, 56.72f, 0.0f);
            break;
        case 619: // Eastern Kingdoms -> Hillsbrad Foothills
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -436.03f, -583.27f, 53.58f, 0.0f);
            break;
        case 620: // Eastern Kingdoms -> Reridge Mountains
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9633.80f, -1875.09f, 68.39f, 0.0f);
            break;
        case 621: // Eastern Kingdoms -> Silverpine Forest
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 641.48f, 1297.84f, 85.45f, 0.0f);
            break;
        case 622: // Eastern Kingdoms -> Stranglethorn Vale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11393.77f, -288.94f, 58.99f, 0.0f);
            break;
        case 623: // Eastern Kingdoms -> Swamp of Sorrows
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10522.55f, -3028.30f, 21.79f, 0.0f);
            break;
        case 624: // Eastern Kingdoms -> The Hinterlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 155.14f, -2014.95f, 122.55f, 0.0f);
            break;
        case 625: // Eastern Kingdoms -> Tirishfal Glades
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2255.5f, 288.511f, 35.1138f, 0.0f);
            break;
        case 626: // Eastern Kingdoms -> Westfall
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10919.09f, 998.47f, 35.47f, 0.0f);
            break;
        case 627: // Eastern Kingdoms -> Wetlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4086.36f, -2610.95f, 47.0143f, 0.0f);
            break;

        case 100: // Main Menu
            // HORDE
            if (player->GetTeam() == HORDE)
            {
                //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界主城传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 1); // "Major Cities"               
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【出生地传送点】|CFF009933 ", GOSSIP_SENDER_MAIN, 3); // "Starting Areas"       
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【初级副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 5); // "Instances"            
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【团队副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 101); // "Raids"                 
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界竞技中心】|CFF009933 ", GOSSIP_SENDER_MAIN, 4015); // "Gurubashi Arena" 
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【卡利姆多区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6010); // "Zones - Kalimdor"     
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【东部王国区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6020); // "Zones - Eastern Kingdoms"     
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【打开个人银行】|CFF009933 ", GOSSIP_SENDER_MAIN, 6030); 
				
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            // ALLIANCE
            else
            {
                //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界主城传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 2); // "Major Cities"               
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【出生地传送点】|CFF009933 ", GOSSIP_SENDER_MAIN, 4); // "Starting Areas"       
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【初级副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 5); // "Instances"            
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【团队副本传送】|CFF009933 ", GOSSIP_SENDER_MAIN, 101); // "Raids"                 
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【世界竞技中心】|CFF009933 ", GOSSIP_SENDER_MAIN, 4015); // "Gurubashi Arena" 
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【卡利姆多区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6010); // "Zones - Kalimdor"     
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【东部王国区域】|CFF009933 ", GOSSIP_SENDER_MAIN, 6020); // "Zones - Eastern Kingdoms"     
                player->ADD_GOSSIP_ITEM(5, " |CFF0000FF【打开个人银行】|CFF009933 ", GOSSIP_SENDER_MAIN, 6030); 
				
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            break;
    }
}
bool GossipSelect_TeleportNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_TeleportNPC(player, _Creature, action);

    return true;
}

enum Enchants
{
    WEP2H_SUPERIOR_IMPACT = 20,
    WEP2H_AGILITY,
    WEP_CRUSADER,
    WEP1H_AGILITY,
    WEP_SPELLPOWER,
    WEP_HEAL,
    OFFHAND_SPIRIT,
    OFFHAND_STAM,
    OFFHAND_FROSTRES,
    CHEST_STATS,
    CLOAK_DODGE,
    CLOAK_SUB,
    CLOAK_ARMOR,
    CLOAK_AGILITY,
    BRACER_STAM,
    BRACER_STR,
    BRACER_HEAL,
    BRACER_INT,
    GLOVES_AGI,
    GLOVES_FIRE,
    GLOVES_FROST,
    GLOVES_SHADOW,
    GLOVES_HEALING,
    BOOTS_AGI,
    BOOTS_SPEED,
    BOOTS_STAM,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant.");
        return;
    }

    if (!enchantid)
    {
        player->GetSession()->SendNotification("Something went wrong.");
        return;
    }

    item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->GetSession()->SendNotification("%s succesfully enchanted", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(5, "Chest", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
    player->ADD_GOSSIP_ITEM(5, "Cloak", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
    player->ADD_GOSSIP_ITEM(5, "Bracers", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
    player->ADD_GOSSIP_ITEM(5, "Gloves", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
    player->ADD_GOSSIP_ITEM(5, "Boots", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
    player->ADD_GOSSIP_ITEM(5, "Mainhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
    player->ADD_GOSSIP_ITEM(5, "Offhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    if (action < 20)
    {
        switch (action)
        {
        case EQUIPMENT_SLOT_CHEST:
            player->ADD_GOSSIP_ITEM(5, "Greater Stats", GOSSIP_SENDER_MAIN, CHEST_STATS);
            break;
        case EQUIPMENT_SLOT_BACK:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Armor", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
            player->ADD_GOSSIP_ITEM(5, "Dodge", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
            player->ADD_GOSSIP_ITEM(5, "Subtlety", GOSSIP_SENDER_MAIN, CLOAK_SUB);
        break;
        case EQUIPMENT_SLOT_WRISTS:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BRACER_STAM);
            player->ADD_GOSSIP_ITEM(5, "Strength", GOSSIP_SENDER_MAIN, BRACER_STR);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, BRACER_HEAL);
            player->ADD_GOSSIP_ITEM(5, "Intellect", GOSSIP_SENDER_MAIN, BRACER_INT);
            break;
        case EQUIPMENT_SLOT_HANDS:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, GLOVES_AGI);
            player->ADD_GOSSIP_ITEM(5, "Fire Power", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
            player->ADD_GOSSIP_ITEM(5, "Frost Power", GOSSIP_SENDER_MAIN, GLOVES_FROST);
            player->ADD_GOSSIP_ITEM(5, "Shadow Power", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
            break;
        case EQUIPMENT_SLOT_FEET:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BOOTS_STAM);
            player->ADD_GOSSIP_ITEM(5, "Minor Speed", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, BOOTS_AGI);
            break;
        case EQUIPMENT_SLOT_MAINHAND:
            player->ADD_GOSSIP_ITEM(5, "Crusader", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
            player->ADD_GOSSIP_ITEM(5, "1H Agility", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "2H Agility", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Spellpower", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, WEP_HEAL);
            break;
        case EQUIPMENT_SLOT_OFFHAND:
            player->ADD_GOSSIP_ITEM(5, "Spirit", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
            player->ADD_GOSSIP_ITEM(5, "Frost Resistance", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
            break;
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    }
    else
    {
        Item* item = nullptr;
        uint32 id = 0;
        switch (action)
        {
            case WEP2H_SUPERIOR_IMPACT:
            case WEP2H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
                {
                    if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                    {
                        player->GetSession()->SendNotification("Requires 2 handed weapon");
                        player->CLOSE_GOSSIP_MENU();
                        return true;
                    }
                }
                if (action == WEP2H_SUPERIOR_IMPACT)
                    id = 1896;
                else if (action == WEP2H_AGILITY)
                    id = 2646;
                break;

            case WEP_CRUSADER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1900;
                break;
            case WEP1H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2564;
                break;
            case WEP_SPELLPOWER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2504;
                break;
            case WEP_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2505;
                break;

            case OFFHAND_SPIRIT:
            case OFFHAND_STAM:
            case OFFHAND_FROSTRES:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
                {
                    player->GetSession()->SendNotification("Requires Shield");
                    player->CLOSE_GOSSIP_MENU();
                    return true;
                }
                if (action == OFFHAND_SPIRIT)
                    id = 1890;
                else if (action == OFFHAND_FROSTRES)
                    id = 926;
                else if (action == OFFHAND_STAM)
                    id = 929;
                break;
            case CHEST_STATS:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
                id = 1891;
                break;
            case CLOAK_DODGE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2622;
                break;
            case CLOAK_SUB:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2621;
                break;
            case CLOAK_ARMOR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 1889;
                break;
            case CLOAK_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 849;
                break;
            case BRACER_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1886;
                break;
            case BRACER_STR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1885;
                break;
            case BRACER_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 2566;
                break;
            case BRACER_INT:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1883;
                break;
            case GLOVES_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2564;
                break;
            case GLOVES_FIRE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2616;
                break;
            case GLOVES_FROST:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2615;
                break;
            case GLOVES_SHADOW:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2614;
                break;
            case GLOVES_HEALING:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2617;
                break;
            case BOOTS_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 904;
                break;
            case BOOTS_SPEED:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 911;
                break;
            case BOOTS_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 929;
                break;
        }
        Enchant(player, item, id);
        player->CLOSE_GOSSIP_MENU();
    }
    return true;
}



void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
{
    uint32 classmask = player->getClassMask();

    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
        if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
            continue;

        player->learnSpell(skillLine->spellId, false);
    }
}
bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
{
    ChatHandler handler(pPlayer->GetSession());
    char* skill_name;

    SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
    skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

    if (!SkillInfo)
    {
        sLog.outError("Profession NPC: received non-valid skill ID");
        return false;
    }

    pPlayer->SetSkill(SkillInfo->id, 300, 300);
    LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
    pPlayer->GetSession()->SendNotification("All recipes for %s learned", skill_name);
    return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Alchemy",              GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Blacksmithing",        GOSSIP_SENDER_MAIN, 2);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Leatherworking",       GOSSIP_SENDER_MAIN, 3);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Tailoring",            GOSSIP_SENDER_MAIN, 4);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Engineering",          GOSSIP_SENDER_MAIN, 5);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Enchanting",           GOSSIP_SENDER_MAIN, 6);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Jewelcrafting",      GOSSIP_SENDER_MAIN, 7);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Inscription",        GOSSIP_SENDER_MAIN, 8);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Herbalism",            GOSSIP_SENDER_MAIN, 9);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Skinning",             GOSSIP_SENDER_MAIN, 10);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Mining",               GOSSIP_SENDER_MAIN, 11);

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "First Aid",            GOSSIP_SENDER_MAIN, 12);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Fishing",              GOSSIP_SENDER_MAIN, 13);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Cooking",              GOSSIP_SENDER_MAIN, 14);

    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
{
    if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
    {
        pPlayer->GetSession()->SendNotification("You already know two primary professions.");
    }
    else
    {
        if (!LearnAllRecipesInProfession(pPlayer, skill))
            pPlayer->GetSession()->SendNotification("Internal error.");
    }
}
bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    switch (action)
    {
    case 1:
        if (!player->HasSkill(SKILL_ALCHEMY))
            CompleteLearnProfession(player, creature, SKILL_ALCHEMY);
        break;
    case 2:
        if (!player->HasSkill(SKILL_BLACKSMITHING))
            CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);
        break;
    case 3:
        if (!player->HasSkill(SKILL_LEATHERWORKING))
            CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
        break;
    case 4:
        if (!player->HasSkill(SKILL_TAILORING))
            CompleteLearnProfession(player, creature, SKILL_TAILORING);
        break;
    case 5:
        if (!player->HasSkill(SKILL_ENGINEERING))
            CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
        break;
    case 6:
        if (!player->HasSkill(SKILL_ENCHANTING))
            CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!player->HasSkill(SKILL_HERBALISM))
            CompleteLearnProfession(player, creature, SKILL_HERBALISM);
        break;
    case 10:
        if (!player->HasSkill(SKILL_SKINNING))
            CompleteLearnProfession(player, creature, SKILL_SKINNING);
        break;
    case 11:
        if (!player->HasSkill(SKILL_MINING))
            CompleteLearnProfession(player, creature, SKILL_MINING);
        break;
    case 12:
        if (!player->HasSkill(SKILL_FIRST_AID))
            CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
        break;
    case 13:
        if (!player->HasSkill(SKILL_FISHING))
            CompleteLearnProfession(player, creature, SKILL_FISHING);
        break;
    case 14:
        if (!player->HasSkill(SKILL_COOKING))
            CompleteLearnProfession(player, creature, SKILL_COOKING);
        break;
    }

    player->CLOSE_GOSSIP_MENU();
    return true;
}

/*
* Custom training dummy script
*/

struct npc_training_dummyAI : ScriptedAI
{
    explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_training_dummyAI::Reset();
    }

    uint32 m_uiCombatTimer;

    void Reset() override
    {
        m_uiCombatTimer = 15000;
    }

    void AttackStart(Unit* /*pWho*/) override {}

    void Aggro(Unit* pWho) override
    {
        SetCombatMovement(false);
    }

    void DamageTaken(Unit* pWho, uint32& uiDamage) override
    {
        m_uiCombatTimer = 15000;
    }

    void SpellHit(Unit* pWho, const SpellEntry* pSpell) override
    {
        m_uiCombatTimer = 15000;
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_creature->isInCombat())
        {
            if (m_uiCombatTimer <= diff)
            {
                EnterEvadeMode();
                m_uiCombatTimer = 15000;
            }
            else
                m_uiCombatTimer -= diff;
        }
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
    uint32 m_maxSummonCount = 200;
    uint32 m_summonCount = 0;
    Creature *m_summons[200];

    npc_summon_debugAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
            m_summons[i] = nullptr;

        Reset();
    }

    void Reset() override
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
        {
            if (m_summons[i])
                ((TemporarySummon*)m_summons[i])->UnSummon();

            m_summons[i] = nullptr;
        }
    }


    void JustDied(Unit* /* killer */) override
    {
        Reset();
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!m_creature->getVictim())
            return;

        if (m_summonCount >= m_maxSummonCount)
            return;

        m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
    }
};

CreatureAI* GetAI_custom_summon_debug(Creature *creature)
{
    return new npc_summon_debugAI(creature);
}

void AddSC_custom_creatures()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "custom_TeleportNPC";
    newscript->pGossipHello = &GossipHello_TeleportNPC;
    newscript->pGossipSelect = &GossipSelect_TeleportNPC;
    newscript->RegisterSelf(false);
    /*
    Commented out to prevent startup error about unused script.

    newscript = new Script;
    newscript->Name = "custom_EnchantNPC";
    newscript->pGossipHello = &GossipHello_EnchantNPC;
    newscript->pGossipSelect = &GossipSelect_EnchantNPC;
    newscript->RegisterSelf(true);

    newscript = new Script;
    newscript->Name = "custom_ProfessionsNPC";
    newscript->pGossipHello = &GossipHello_ProfessionNPC;
    newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
    newscript->RegisterSelf(true);

    newscript = new Script;
    newscript->Name = "npc_training_dummy";
    newscript->GetAI = &GetAI_npc_training_dummy;
    newscript->RegisterSelf();
    */

    newscript = new Script;
    newscript->Name = "custom_npc_summon_debugAI";
    newscript->GetAI = &GetAI_custom_summon_debug;
    newscript->RegisterSelf(false);
}
