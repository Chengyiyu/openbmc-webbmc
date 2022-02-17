#pragma once

#include <app.hpp>
#include <async_resp.hpp>
#include <nlohmann/json.hpp>

namespace crow
{
namespace caesar_api
{

inline void requestRoutes(App& app)
{
    BMCWEB_ROUTE(app, "/caesar/v1/")
        .methods(boost::beast::http::verb::get)(
            [](const crow::Request&,
               const std::shared_ptr<bmcweb::AsyncResp>& asyncResp) {
                asyncResp->res.jsonValue["@odata.type"] =
                    "#wistron.v1_0_0.CaesarServiceRoot";
                asyncResp->res.jsonValue["@odata.id"] = "/caesar/v1";
                asyncResp->res.jsonValue["Id"] = "Caesar Rest RootService";
                asyncResp->res.jsonValue["Name"] = "Caesar Service Root";
                asyncResp->res.jsonValue["Version"] = "1.0.0";
            });
}

} // namespace caesar_api
} // namespace crow
