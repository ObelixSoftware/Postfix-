for file in $(ls *.cpp *.h | sort); do
  echo "// File: $file" >> combined.txt
  cat "$file" >> combined.txt
  echo "" >> combined.txt  # Add a newline for separation
done