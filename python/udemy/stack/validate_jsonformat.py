"""
Input {'key1': 'value1', 'key2': [1, 2, 3], 'key3': (1, 2, 3)}  Output True
Input [{'key1': 'value1', 'key2': [1, 2, 3], 'key3': (1, 2, 3)} Output False
"""
def validate_format(chars:str) -> bool:
    # count {, [, (
    stack = []
    look_up = {'{': '}', '[': ']', '(': ')'}
    for char in chars:
        if char in look_up.keys():
            stack.append(look_up[char])
        if char in look_up.values():
            # No correct pair cases -> return false
            if not stack:
                return False
            # different pair
            if char != stack.pop():
                return False            
    if stack:
        return False

    return True

if __name__ == "__main__":
    chars = "{'key1': 'value1', 'key2': [1, 2, 3], 'key3': (1, 2, 3)}"
    chars = "[{'key1': 'value1', 'key2': [1, 2, 3], 'key3': (1, 2, 3)}"
    result = validate_format(chars)
    print(result)