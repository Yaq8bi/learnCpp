#!/usr/bin/env python3

import json
import sys
import os

# Load data.json
try:
    with open("data.json") as file:
        try:
            message = json.load(file)
        except json.JSONDecodeError:
            print("Failed to read and parse the JSON file")
            sys.exit(1)
except FileNotFoundError:
    print("Failed to open the JSON file")
    sys.exit(1)

signals = message.get("signals", [])
del message  # Free up memory

# Define table headers
title = {
    "name": "Signal",
    "type": "Type",
    "length": "Length",
    "comment": "Description"
}

# Determine column widths
size = {key: len(title[key]) for key in title}

for signal in signals:
    for key in title:
        value = str(signal.get(key, ""))
        size[key] = max(size[key], len(value))

# Define file path
output_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), './../lib/signals')
output_file = os.path.join(output_dir, 'signal.txt')

# Ensure the directory exists
os.makedirs(output_dir, exist_ok=True)

# Open the file for writing
with open(output_file, 'w') as f:
    # Print header to file
    header = " | ".join(title[key].ljust(size[key]) for key in title)
    f.write(header + "\n")
    f.write("-" * (sum(size.values()) + 9) + "\n")
    
    # Print signal data to file
    for signal in signals:
        length = str(signal.get("length", "-")).rjust(size["length"] // 2 + 1)
        row = " | ".join(
            str(signal.get(key, "-")).ljust(size[key]) if key != "length" else length.ljust(size[key])
            for key in title
        )
        f.write(row + "\n")

print(f"Signals successfully saved to {output_file}")
