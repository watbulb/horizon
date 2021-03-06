#pragma once
#include "track.hpp"
#include "common/common.hpp"
#include "common/junction.hpp"
#include "nlohmann/json_fwd.hpp"
#include "util/uuid.hpp"
#include "util/uuid_provider.hpp"
#include "util/uuid_ptr.hpp"
#include <fstream>
#include <map>
#include <vector>

namespace horizon {
using json = nlohmann::json;

class ConnectionLine : public UUIDProvider {
public:
    ConnectionLine(const UUID &uu, const json &j, class Board *brd = nullptr);
    ConnectionLine(const UUID &uu);

    void update_refs(class Board &brd);
    virtual UUID get_uuid() const;

    UUID uuid;

    Track::Connection from;
    Track::Connection to;

    json serialize() const;
};
} // namespace horizon
