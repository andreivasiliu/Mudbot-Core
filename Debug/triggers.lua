-- Triggers

-- add_lua_(type)_trigger( ID, PATTERN, FUNCTION(args, matches), CLASS, ARGS)

-- :: Warnings

add_lua_pattern_trigger(
	"warnings",
	"^The beginnings of a fiery portal appear before you\\.$",
	function(args, matches)
		i_warning("Portal Incoming!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) stomps a foot mightily into the ground and a quickly-moving spiderweb of cracks spreads outwards from the impact towards you\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Chasm 1/3 (web/sleep/paralysis)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^As the spiderweb of cracks reaches you, ([A-Z][a-z]+) quickly drops to the ground and begins to pry open the splits into a gaping chasm, using naught but (?:his|her) sheer strength alone\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Chasm 2/3 (web/sleep/paralysis)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Rapidly spinning now, the Wheel moves at a blur, the pointed edges along the sides barely visible\\. A wave of dark, necromantic energy shoots out from the Wheel, fixing itself upon you\\.$",
	function(args, matches)
		i_warning("Wheel Tarot! (Rip Card)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Missing only the center circle, the Wheel of Misfortune looms over your surroundings as its expansion finishes\\. With a maniacal grin, [A-Z][a-z]+ draws forth a stream of life essence from your body, channeling it towards the massive Wheel\\. As the essence converges upon the Wheel's center, the construction is completed and it begins to slowly, inexorably, spin around its axle\\.$",
	function(args, matches)
		i_warning("Wheel Tarot! (Rip Card)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^An unstable point of singularity comes falling down from above to land with a thump\\.$",
	function(args, matches)
		i_warning("MOVE! MOVE! >>>SINGULARITY<<< MOVE! MOVE! (sky)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^A loud crack is heard as all the spokes in the Wheel of Misfortune is split in two\\. The triangular pieces are swirled around the outer circle, creating sharp points along the outer rim\\. The Wheel picks up speed, swaying erratically from side to side, aiming at your exposed limbs\\.$",
	function(args, matches)
		i_warning("Wheel Tarot! (Rip Card)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^A holocaust globe comes falling down from above to land with a 'THUMP\\.'$",
	function(args, matches)
		i_warning("MOVE! MOVE! >>>HOLOCAUST<<< MOVE! MOVE! (sky)")
	end,
	"",
	"")


add_lua_pattern_trigger(
	"warnings",
	"^A beam of prismatic light suddenly shoots into the room\\.$",
	function(args, matches)
		i_warning("Prismatic Beam Incoming!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) waves (?:his|her) palm towards ([A-Z][a-z]+), who abruptly vanishes from existence\\.$",
	function(args, matches)
		i_warning(matches[3] .. " has been banished by " .. matches[2] .. "!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) swings the crackling mace about (?:his|her) head, gathering momentum as s?he bears down on you\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Judging 2/4 (web/sleep/paralysis)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) stills himself in preparation to bestow the Brand of the ([\a]+) upon you\\.$",
	function(args, matches)
		i_warning("Elemental Brand!!! " .. matches[3] .. " by " .. matches[2] .. ") (disrupt or move)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) stands firm and looks down towards the ground\\. The ground begins to rumble ominously\\.$",
	function(args, matches)
		i_warning("Chasm!!! (" .. matches[2] .. ") (web, attack, or move)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) snaps {?:his|her} fingers\\, and bits of fire dance about you\\, causing your lit pipes to burn more quickly\\.$",
	function(args, matches)
		i_warning("PIPES EMPTIED BY " .. matches[2] .. "!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) slowly raises (?:his|her) head and you see (?:his|her) eyes glowing bright white\\.$",
	function(args, matches)
		i_warning("DELIVERANCE (No damaging " .. matches[2] .. ")")
	end,
	"",
	"")

death_tarot = 0
add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) rubs a tarot card on your arm\\. You feel slightly nauseated and drained\\.$",
	function(args, matches)
		death_tarot = death_tarot + 1
		i_warning("DEATH TAROT! (".. death_tarot .. "/7 by " .. matches[2] .. ")")
	end,
	"",
	"")


add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) relaxes (?:his|her) muscles and starts to vibrate slightly\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Crystal Home! (Sleep/Paralyse/Web)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) raises (?:his|her) spiritual mace over you to pass judgement on your sins, and it begins to crackle with righteous fire\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Judging 1/4 (web/sleep/paralysis)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) mace begins to make a high-pitched keening sound as it rapidly spins over (?:his|her) head\\. You have only moments left to escape before you are judged!$",
	function(args, matches)
		i_warning(matches[2] .. " Judging 3/4 (web/sleep/paralysis)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) flings a tarot card at you and upon impact, it disappears\\. An ominous silence overtakes your surroundings\\.$",
	function(args, matches)
		i_warning("DEATH TAROT COMING! (run)")
		death_tarot = nil
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) fashions a holocaust globe out of pure elemental fire and arms it\\.$",
	function(args, matches)
		i_warning("MOVE! MOVE! >>>HOLOCAUST<<< MOVE! MOVE! (" .. matches[2] .. ")")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) closes (?:his|her) eyes, focusing on the magick about (?:him|her)\\.$",
	function(args, matches)
		i_warning(matches[2] .. " Focusing Vibes! (WATCHOUT)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) causes a point of singularity to ripple into existence\\. It pulses brightly and crackles with potentiality\\.$",
	function(args, matches)
		i_warning("MOVE! MOVE! >>>SINGULARITY<<< MOVE! MOVE! (" .. matches[2] .. ")")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) bows (?:his|her) head in silent prayer\\.$",
	function(args, matches)
		i_warning("DELIVERANCE COMING UP (" .. matches[2] .. ")")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) begins to bear down on you with",
	function(args, matches)
		i_warning("BEHEAD HALFWAY COMPLETED BY " .. matches[2] .. " (web, attack, or move)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) begins to bear down on ([A-Z][a-z]+) with (?:his|her) whirling rapier\\.$",
	function(args, matches)
		i_warning(matches[2] .. " BEHEADING " .. matches[3] .. "!!!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^[A-Z][a-z]+ points a ring of pestilence at you\\.$",
	function(args, matches)
		i_warning("Pestilence")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^[A-Z][a-z]+ blows an aeon tarot at you, destroying your speed defence\\.$",
	function(args, matches)
		i_warning("Speed stripped by Aeon Tarot")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Your spirit writhes in torment under the glare of the angel\\.$",
	function(args, matches)
		i_warning("Spiritwrack")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Your legs tremble slightly as a yellow jaundice begins to creep through your now-pale features\\.$",
	function(args, matches)
		i_warning("Voyria (4/5)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You think of ([A-Z][a-z]+) and find that your feelings for (him|her) have changed\\.$",
	function(args, matches)
		i_warning("Changed Heart! (" .. matches[2] .. ")")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You move sluggishly into action\\.$",
	function(args, matches)
		i_warning("Aeon")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You hear ([A-Z][a-z]+)'s voice in your mind and feel irresistibly compelled to \"(.+)\\.\"$",
	function(args, matches)
		i_warning("Mind Force: " .. matches[3] .. " (" .. matches[2] .. ")")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You feel [A-Z][a-z]+'s eyes upon you, and feel your sense of time slow as clumsiness overcomes you\\.$",
	function(args, matches)
		i_warning("Infirmity speed stripped")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You feel [A-Z][a-z]+'s eyes on you\\. A weariness comes over you, and it is difficult to move your limbs\\.$",
	function(args, matches)
		i_warning("Aeon")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^You feel irresistibly compelled to \"(.+)\\.\"$",
	function(args, matches)
		i_warning("Mind Force: " .. matches[2] .. "")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^With a grand gesture of righteous fury, [A-Z][a-z]+ bedevils you",
	function(args, matches)
		i_warning("Bedevil! (DIAG)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Thrashing wildly, you struggle against the death grip of ([A-Z][a-z]+)'s whip wrapped around your neck\\.$",
	function(args, matches)
		i_warning(matches[2] .. " choking you!! (Web/Paralyse/Prone)")
	end,
	"",
	"")
	
add_lua_pattern_trigger(
	"warnings",
	"^The wisp around the head of ([A-Z][a-z]+) glows a dark red momentarily before forming a hardened shield around him\\.$",
	function(args, matches)
		i_warning(matches[2] .. " shielded!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^The dark void of terror fills your mind as, horribly, blood begins to seep out of every pore on your body\\.$",
	function(args, matches)
		i_warning("Voyria (5/5)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^Blood begins to slowly drip from your nose\\.$",
	function(args, matches)
		i_warning("Voyria (2/5)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^As the retardation vibration embeds itself, time itself appears to slow\\.$",
	function(args, matches)
		i_warning("Retardation Vibe!")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^A dart streaks from out of nowhere and slams into you\\.$",
	function(args, matches)
		i_warning("Dart trap! (move)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) slips behind your prone body, and wraps (?:his|her) whip around your neck tightly\\.$",
	function(args, matches)
		i_warning(matches[2] .. " choking you!! (Web/Paralyse/Prone)}")
	end,
	"",
	"")
	
add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) raises .+ over (?:his|her) head and begins to swing it in a wide circle, gaining speed as s?he goes\\.$",
	function(args, matches)
		i_warning("CLEAVE STARTED BY " .. matches[2] .. " (stand, web, attack, or move)}")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) slowly pulls back .+, readying (himself|herself) for a devastating strike\\.$",
	function(args, matches)
		i_warning(matches[2] .. " SHATTERING! (Interrupt!)}")
	end,
	"",
	"")
	
	add_lua_pattern_trigger(
	"warnings",
	"^Wildly spinning .+, ([A-Z][a-z]+) prepares to massacre you with a devastating slash\\.$",
	function(args, matches)
		i_warning(matches[2] .. " IS DISMEMBERING YOU! (Interrupt!)}")
	end,
	"",
	"")
	
	add_lua_pattern_trigger(
	"warnings",
	"^A viscous blue sheen envelops .+ as ([A-Z][a-z]+) draws it back, the motion accompanied by an odd tugging sensation from deep within that threatens to steal your breath with it\\.$",
	function(args, matches)
		i_warning("REAVE STARTED BY " .. matches[2] .. " (stand, web, attack, or move)}")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"warnings",
	"^([A-Z][a-z]+) quickly flings a tarot card at you, and you feel unreasonable lust for",
	function(args, matches)
		i_warning("Lust Tarot! (" .. matches[2] .. ")")
	end,
	"",
	"")


add_lua_pattern_trigger(
	"",
	"^Your heart thumps as you realize that you have but seconds left to escape whatever fate awaits you\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 6/7 (run)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"",
	"^Sparks of multicoloured light begin to dance in your mind\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 3/7 (run)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"",
	"^Arcs of white light begin to flash across your vision, radiant and bright\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 5/7 (run)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"",
	"^An odd sensation of warmth begins to fill your body\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 4/7 (run)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"",
	"^A shiver runs down your spine, and you feel an instinctive urge to run as far and fast as you can\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 1/7 (run)")
	end,
	"",
	"")

add_lua_pattern_trigger(
	"",
	"^A shimmering image of the face of ([A-Z][a-z]+) appears fleetingly before you, frowning in concentration\\.$",
	function(args, matches)
		i_warning("RADIANCE - PHASE 2/7 (" .. matches[2] .. " -- run)")
	end,
	"",
	"")