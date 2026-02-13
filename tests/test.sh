#!/bin/bash

echo "Running Project Tests..."

# Check required files
required_files=(
  "index.html"
  "form.html"
  "studentdata.html"
  "access.html"
  "style.css"
)

for file in "${required_files[@]}"
do
  if [ ! -f "$file" ]; then
    echo "❌ Test Failed: $file is missing!"
    exit 1
  else
    echo "✅ $file exists."
  fi
done

echo "🎉 All tests passed successfully!"
