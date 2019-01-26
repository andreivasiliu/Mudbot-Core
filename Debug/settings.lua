-- Auto Scans

g_Auto_Scans.health			= 1
g_Auto_Scans.mana			= 1
g_Auto_Scans.herb			= 1
g_Auto_Scans.precache		= 1
g_Auto_Scans.prerestore		= 1
g_Auto_Scans.salve			= 1
g_Auto_Scans.elixir			= 1
g_Auto_Scans.moss			= 1
g_Auto_Scans.stand			= 1
g_Auto_Scans.writhe			= 1
g_Auto_Scans.wake			= 1
g_Auto_Scans.smoke			= 1
g_Auto_Scans.defence		= 1
g_Auto_Scans.tree			= 1
g_Auto_Scans.rage			= 0
g_Auto_Scans.renew			= 1
g_Auto_Scans.focus			= 1
g_Auto_Scans.clot			= 1
g_Auto_Scans.reject			= 1
g_Auto_Scans.parry			= 1
g_Auto_Scans.aura			= 1
g_Auto_Scans.breath			= 0
g_Auto_Scans.cloak			= 1
g_Auto_Scans.mass			= 1
g_Auto_Scans.lock_breaker	= 1

-- Settings

g_Settings.health_sip	= 0.9
g_Settings.mana_sip		= 0.9
-- Options for sip_priority: SIP_PRIORITY_SMART, SIP_PRIORITY_LINK
g_Settings.sip_priority = SIP_PRIORITY_SMART
g_Settings.sip_smart_health = 0.6
g_Settings.sip_smart_mana = 0.6
-- Options for sip_smart_default: SIP_SMART_HEALTH, SIP_SMART_MANA
g_Settings.sip_smart_default = SIP_SMART_HEALTH
-- Options for link_elixir: LINK_SIP_HEALTH, LINK_SIP_MANA, LINK_SIP_AUTO
g_Settings.link_elixir = LINK_SIP_AUTO
g_Settings.link_sip = 0.95
g_Settings.health_moss	= 0.75
g_Settings.mana_moss	= 0.75
g_Settings.clot_mana	= 0.5
g_Settings.insomnia_mana = 0.5
g_Settings.mana_rage = 0.33  
g_Settings.mana_focus = 0
g_Settings.health_nimbleness = 0.5
g_Settings.pipe_sets	= 1
g_Settings.use_allsight = 1
g_Settings.prerestore_min = 16.0
g_Settings.renew_cmd = "renew"
-- Options for default_parry: LIMB_NONE, LIMB_HEAD, LIMB_TORSO, LIMB_LEFT_ARM, ect...
g_Settings.default_parry = LIMB_HEAD
-- Options for parry_mode: PARRY_MODE_LYCAN, PARRY_MODE_NORM
-- Note: This setting is for parrying logic. For example, PARRY_MODE_LYCAN is for fighting against Lycans.
g_Settings.parry_mode = PARRY_MODE_NORM
g_Settings.use_stability = 0
g_Settings.bal_color = "\27[0;37;42m"
g_Settings.eq_color = "\27[0;37;42m"
g_Settings.display_echos = 1
g_Settings.latency_fst = 0.65
g_Settings.sip_reckless_default = SIP_RECKLESS_HEALTH
g_Settings.sip_reckless_alternate_count = 3

-- Precache
set_precache("bloodroot", "2");
set_precache("goldenseal", "2");
set_precache("moss", "2");
set_precache("kelp", "2");
set_precache("bayberry", "2");
set_precache("hawthorn", "2");



