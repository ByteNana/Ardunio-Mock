# ==============================================================================
# Variables
# ==============================================================================

SRC_DIRS := src test examples
BUILD_DIR := build

# ==============================================================================
# Argument Capture
# ==============================================================================

# Get the log level from command line arguments (exclude non-level targets)
LOG_LEVEL_ARG := $(filter-out \
  help test build setup all clean format check check-format \
  test-esp32 flash-esp32-test esp32 esp32-test, \
  $(MAKECMDGOALS))

# Set default log level if no argument provided
LOG_LEVEL := $(if $(LOG_LEVEL_ARG),$(LOG_LEVEL_ARG),3)

# ==============================================================================
# Make Configuration
# ==============================================================================

# Suppress recursive make directory noise
MAKEFLAGS += --no-print-directory

# Set default target to 'help'
.DEFAULT_GOAL := help
