pub fn LinkedList(comptime T: type) type {
    return struct {
        pub const Node = struct {
            prev: ?*Node = null,
            next: ?*Node = null,
            data: T,
        };

        first: ?*Node = null,
        last: ?*Node = null,
        len: usize = 0,

        pub fn push(self: *LinkedList(T), node: *Node) void {
            node.prev = self.last;
            if (self.last) |last_node|
                last_node.next = node
            else
                self.first = node;
            self.last = node;
            self.len += 1;
        }

        pub fn pop(self: *LinkedList(T)) ?*Node {
            if (self.last) |last_node| {
                self.last = last_node.prev;
                self.len -= 1;
                if (self.len == 0) self.first = null;
                return last_node;
            }
            return null;
        }

        pub fn shift(self: *LinkedList(T)) ?*Node {
            if (self.first) |first_node| {
                self.first = first_node.next;
                self.len -= 1;
                if (self.len == 0) self.last = null;
                return first_node;
            }
            return null;
        }

        pub fn unshift(self: *LinkedList(T), node: *Node) void {
            node.next = self.first;
            if (self.first) |first_node|
                first_node.prev = node
            else
                self.last = node;
            self.first = node;
            self.len += 1;
        }

        pub fn delete(self: *LinkedList(T), node: *Node) void {
            var curr: ?*Node = self.first;
            while (curr != null) {
                const cur: *Node = curr.?;
                if (cur.data == node.data) {
                    const prev = cur.prev;
                    const next = cur.next;
                    if (self.first.?.data == node.data) self.first = next;
                    if (self.last.?.data == node.data) self.last = prev;
                    if (prev != null) prev.?.next = next;
                    if (next != null) next.?.prev = prev;
                    self.len -= 1;
                    return;
                }
                curr = cur.next;
            }
        }
    };
}
