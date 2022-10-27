##
## The enum and the token structure represent the tokens in our lexical analyzer
##
@enum TokenType begin
    Eof
    Idk
    Add
    X1
    X2
    X3
    Id
    Comma
end

struct Token
    ttype::TokenType
    value::String
end

##
## Represents a lexical analyzer for holding the current state
##
mutable struct Lex
    input::String
    buffer::String
    pos::Int32
    stack::Vector{Token}
end

##
## Setups the lexical analyzer
##
function lex_init(input)
    lex = Lex(string(input, "  "), "", 1, [])
    return lex
end

##
## Returns the next token in the stream
##
function lex_get_next_char(lex)
    lex2 = lex
    c = lex.input[lex.pos]
    lex2.pos += 1
    return (c, lex2)
end

function lex_is_symbol(c)
    if c == ',' return true
    end
    return false
end

function lex_is_keyword(lex)
    if lex.buffer == "add" return true
    elseif lex.buffer == "x1" return true
    elseif lex.buffer == "x2" return true
    elseif lex.buffer == "x3" return true
    end
    return false
end

function lex_get_symbol(c)
    if c == ',' return Comma::TokenType
    end
    return Idk::TokenType
end

function lex_get_keyword(lex)
    if lex.buffer == "add" return Add::TokenType
    elseif lex.buffer == "x1" return X1::TokenType
    elseif lex.buffer == "x2" return X2::TokenType
    elseif lex.buffer == "x3" return X3::TokenType
    end
    return Idk::TokenType
end

function lex_get_next(lex1)
    lex = lex1
    if length(lex.stack) > 0
        token = pop!(lex.stack)
        return (token, lex)
    end
    
    token = Token(Eof::TokenType, "")
    if lex.pos >= length(lex.input)
        return (token, lex)
    end
    
    global (c, lex) = lex_get_next_char(lex)
    while lex.pos <= length(lex.input)
        if c == ' ' || lex_is_symbol(c)
            if lex_is_symbol(c)
                token2 = Token(lex_get_symbol(c), "")
                if length(lex.buffer) > 0
                    push!(lex.stack, token2)
                else
                    return (token2, lex)
                end
            end
            
            if length(lex.buffer) == 0
                global (c, lex) = lex_get_next_char(lex)
                continue
            end
            
            if lex_is_keyword(lex)
                token = Token(lex_get_keyword(lex), "")
                lex.buffer = ""
                return (token, lex)
            else
                token = Token(Id::TokenType, lex.buffer)
                lex.buffer = ""
                return (token, lex)
            end
        else
            lex.buffer = string(lex.buffer, c)
        end
        global (c, lex) = lex_get_next_char(lex)
    end
    
    return (token, lex)
end

##
## Our driver program
##
input = "add x1, x2, x3"
lex = lex_init(input)

(token, lex) = lex_get_next(lex)
while token.ttype != Eof::TokenType
    println(token)
    global (token, lex) = lex_get_next(lex)
end
println(token)

