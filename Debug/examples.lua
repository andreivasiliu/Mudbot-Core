-- Begin comment block
--[[

limb_targets = { "none", "none" }

-- Offense

create_group("offense", "", 1, 0)
set_group("offense")

-- :: Targetting

add_lua_oninput_trigger(
	"targetting",
	"^t (.+)$",
	function(args, matches)
		target = matches[2]
		no_input()
	end,
	"",
	"")

add_lua_oninput_trigger(
	"targetting",
	"^p(?:ush)?l(?:imb)?t(?:arget)? (.+)",
	function(args, matches)
		limb_targets[2] = limb_targets[1]
		limb_targets[1] = matches[2]
		no_input()
	end,
	"",
	"")

-- :: Lycanthropy

create_group("lycanthropy", "", 1, 0)
set_group(".|lycanthropy")

add_lua_oninput_trigger(
	"",
	"^br$",
	function(args, matches)
		send("claw " .. limb_targets[1] .. " of " .. target)
		send("claw " .. limb_targets[2] .. " of " .. target)
	end,
	"",
	"")

set_group("")

-- :: Templar

create_group("templar", "", 1, 0)
set_group(".|templar")

add_lua_oninput_trigger(
	"",
	"^gon$",
	function(args, matches)
		enable_group("gauche_impale")
		no_input()
	end,
	"",
	"")

add_lua_oninput_trigger(
	"",
	"^goff$",
	function(args, matches)
		disable_group("gauche_impale")
		no_input()
	end,
	"",
	"")

add_lua_pattern_trigger(
	"gauche_impale",
	"^With a swift movement you dart in toward ([A-Z][a-z]+) and stab (?:her|him) with ",
	function(args, matches)
		send("impale " .. matches[2])
	end,
	"",
	"")

disable_group("gauche_impale")

set_group("")

-- :: Defenses

add_defense_ex("bodyblock", "bdb", "^You are trying to absorb blows to your body\\.$", "^You ready yourself to block as best you can\\.$", true, true, false)

--]]
-- End comment block