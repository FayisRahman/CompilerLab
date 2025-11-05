# Directory containing .gv files
GV_DIR = .
OUT_DIR = .

# Find all .gv files and create matching .png names
GV_FILES = $(wildcard $(GV_DIR)/*.gv)
PNG_FILES = $(GV_FILES:.gv=.png)

# Default target
all: $(PNG_FILES)
	@echo "✅ All .gv files converted to .png!"

# Rule to convert each .gv → .png
%.png: %.gv
	@echo "🎨 Converting $< → $@"
	dot -Tpng $< -o $@

# Clean up generated images
clean:
	@echo "🧹 Removing all .png files..."
	rm -f $(PNG_FILES)
	rm -f $(GV_FILES)

.PHONY: all clean
