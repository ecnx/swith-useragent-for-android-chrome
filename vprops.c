/**
 * Extract single property
 */
static int props_get(const char * props, const char * name, char * value, size_t len) {
    size_t name_len;
    size_t copy_len;
    const char * start_ptr;
    const char * end_ptr;

    if (strchr(name, '#') == name) {
        return -1;
    }

    name_len = strlen(name);

    start_ptr = props;
    while ((start_ptr = strstr(start_ptr, name))) {
        if (start_ptr[name_len] != '=') {
            start_ptr += name_len;
            continue;
        }

        if (start_ptr == props || start_ptr[-1] == '\n') {
            break;
        }

        start_ptr += name_len;
    }

    if (!start_ptr) {
        return -1;
    }

    start_ptr += name_len + 1;

    end_ptr = start_ptr;

    while ( * end_ptr && * end_ptr != '\r' && * end_ptr != '\n') {
        end_ptr++;
    }

    if ((copy_len = end_ptr - start_ptr) >= len) {
        return -1;
    }

    memcpy(value, start_ptr, copy_len);
    value[copy_len] = '\0';

    return 0;
}

/**
 * Get virtual property by name
 */
static int get_virtual_property_ret(const char * name, char * value, size_t size) {
    const char * vprops = getenv("VPROPS");
    if (!vprops) {
        return -1;
    }
    return props_get(vprops, name, value, size);
}

/**
 * Get virtual property by name no return value
 */
static void get_virtual_property(const char * name, char * value, size_t size) {
    if (get_virtual_property_ret(name, value, size) < 0) {
        if (size > 0) {
            value[0] = '\0';
        }
    }
}
