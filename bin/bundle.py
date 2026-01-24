#!/usr/bin/env python3
import sys
import re
from pathlib import Path

# 設定: 展開済みヘッダの追跡
included_headers = set()

def resolve_includes(file_path: Path, lib_path: Path) -> str:
    if not file_path.exists():
        sys.stderr.write(f"Error: {file_path} not found.\n")
        sys.exit(1)

    content = ""
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # Regex: #include "..." を検知 ( <...> は無視)
    pattern = re.compile(r'^\s*#include\s+"(.+)"\s*$')

    for line in lines:
        match = pattern.match(line)
        if match:
            header_name = match.group(1)
            header_path = lib_path / header_name
            
            # #pragma once の代わり: 二重展開防止
            if header_path.resolve() in included_headers:
                continue
            
            included_headers.add(header_path.resolve())
            
            # 再帰的に展開
            content += f"// --- begin {header_name} ---\n"
            content += resolve_includes(header_path, lib_path)
            content += f"// --- end {header_name} ---\n"
        else:
            # #pragma once は出力しない
            if "#pragma once" not in line:
                content += line
    return content

if __name__ == "__main__":
    # 引数処理
    if len(sys.argv) < 3:
        print("Usage: ./bundle.py <source_file> <lib_dir>")
        sys.exit(1)

    src_file = Path(sys.argv[1])
    lib_dir = Path(sys.argv[2])

    result = resolve_includes(src_file, lib_dir)
    print(result)
