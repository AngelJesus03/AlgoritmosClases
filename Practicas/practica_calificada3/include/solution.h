#pragma once
namespace ods{

struct SegmentTree{
    int n{0};
    int tree[800005]{};

    void build(int node, int start, int end);
    void remove(int node, int start, int end, int idx);
    int kesimo(int node, int start, int end, int k);
};

} // namespace ods