# Compiler Project

who knows if i actually work on this

## Goal

The goal of this is to create a compiler for the language Lox, stolen shamelessly from [Crafting Interpretors](https://craftinginterpreters.com/).

## Phases

### Lexical Analysis

Also known as *scanning*. Convert a stream of input characters to Tokens.

### Syntax Analysis

Also known as *parsing*. Uses tokens to create a syntax tree. Each node represents an operation and the children of a node represent the arguments of the parent operation.