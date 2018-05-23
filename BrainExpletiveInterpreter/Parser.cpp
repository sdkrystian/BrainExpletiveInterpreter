#include "stdafx.h"
#include "Parser.h"

int GetBraceMatchClose(const char* str, size_t len, int brace)
{
  int opening = 0;
  int closing = 0;
  for (int i = brace + 1; i < len; i++)
  {
    char ins = str[i];
    if (ins == '[')
    {
      opening++;
    }
    else if (ins == ']')
    {
      closing++;
      if (closing - 1 == opening)
        return i;
    }
  }
  return -1;
}

int GetBraceMatchOpen(const char* str, int brace)
{
  int opening = 0;
  int closing = 0;
  for (int i = brace - 1; i >= 0; i--)
  {
    char ins = str[i];
    if (ins == ']')
    {
      closing++;
    }
    else if (ins == '[')
    {
      opening++;
      if (opening - 1 == closing)
        return i;
    }
  }
  return -1;
}

int ExecuteIns(const char* str, size_t len, char ins, int& index, char* block)
{
  switch (ins)
  {
    case '+':
      ++(*block);
      break;
    case '-':
      --(*block);
      break;
    case '>':
      return 1;
    case '<':
      return -1;
    case '.':
      putchar(*block);
      break;
    case ',':
      (*block) = getchar();
      break;
    case '[':
      if (*block == 0)
        index = GetBraceMatchClose(str, len, index);
      break;
    case ']':
      if (*block != 0)
        index = GetBraceMatchOpen(str, index) - 1;
      break;
    default:
      return 0;
  }
  return 0;
}

void brainexpletive::ExecuteBrainExpletive(const char* str, size_t len)
{
  char* block_begin = new char[30000];
  memset(block_begin, 0, 30000);
  int block_curr = 0;
  for (int i = 0; i < len; ++i)
  {
    char ins = str[i];
    block_curr += ExecuteIns(str, len, str[i], i, &block_begin[block_curr]);
    if (i < 0)
    {
      return;
    }
  }
  delete[] block_begin;
}