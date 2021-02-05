#pragma once
#include "snowflake.hpp"
#include "json.hpp"
#include <string>

struct UserData {
    enum {
        DiscordEmployee = 1 << 0,
        PartneredServerOwner = 1 << 1,
        HypeSquadEvents = 1 << 2,
        BugHunterLevel1 = 1 << 3,
        HouseBravery = 1 << 6,
        HouseBrilliance = 1 << 7,
        HouseBalance = 1 << 8,
        EarlySupporter = 1 << 9,
        TeamUser = 1 << 10, // no idea what this is
        System = 1 << 12,
        BugHunterLevel2 = 1 << 14,
        VerifiedBot = 1 << 16,
        EarlyVerifiedBotDeveloper = 1 << 17,

        MaxFlag = EarlyVerifiedBotDeveloper,
    };

    static const char *GetFlagName(uint64_t flag);
    static const char *GetFlagReadableName(uint64_t flag);

    Snowflake ID;
    std::string Username;
    std::string Discriminator;
    std::string Avatar; // null
    std::optional<bool> IsBot;
    std::optional<bool> IsSystem;
    std::optional<bool> IsMFAEnabled;
    std::optional<std::string> Locale;
    std::optional<bool> IsVerified;
    std::optional<std::string> Email; // null
    std::optional<uint64_t> Flags;
    std::optional<int> PremiumType; // null
    std::optional<uint64_t> PublicFlags;

    // undocumented (opt)
    std::optional<bool> IsDesktop;
    std::optional<bool> IsMobile;
    std::optional<bool> IsNSFWAllowed; // null
    std::optional<std::string> Phone;  // null?

    friend void from_json(const nlohmann::json &j, UserData &m);
    friend void to_json(nlohmann::json &j, const UserData &m);
    void update_from_json(const nlohmann::json &j);

    bool HasAvatar() const;
    bool HasAnimatedAvatar() const;
    std::string GetAvatarURL(std::string ext = "png", std::string size = "32") const;
    Snowflake GetHoistedRole(Snowflake guild_id, bool with_color = false) const;
    std::string GetMention() const;
    std::string GetEscapedString() const;
};
