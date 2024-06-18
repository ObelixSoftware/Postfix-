for file in $(ls *.h *.cpp | sort); do
  echo "// File: $file" >> combined.txt
  cat "$file" >> combined.txt
  echo "" >> combined.txt  # Add a newline for separation
done