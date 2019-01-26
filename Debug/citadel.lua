-- Start
-- Script: citadel.lua

require "settings"
require "defenses"
require "lookups"
require "utility"
require "triggers"
require "examples"

-- Create custom.lua if it doesn't already exist.
file = io.open("custom.lua", "a")
file:close()
require "custom"