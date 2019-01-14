#include <cqhttp/extension/extension.h>

using namespace std;
using namespace cqhttp::extension;
using nlohmann::json;

struct SomeExtension : Extension {
    Info info() const override {
        static Info i;
        i.name = u8"某某扩展";
        i.version = "0.0.1";
        i.build_number = 1;
        i.description = u8"提供某某功能。";
        return i;
    }

#define CONF_PREFIX "some_ext."

    void on_create(Context &ctx) override {
        enable_ = ctx.get_config_bool(CONF_PREFIX "enable", false);
        if (enable_) {
            // 初始化
        }
    }

    void on_destroy(Context &ctx) override {
        // 释放资源
    }

    void on_event(EventContext &ctx) override {
        if (enable_) {
            // 处理事件

            // 例如，直接回复私聊消息
            if (ctx.data["post_type"] == "message" && ctx.data["message_type"] == "private") {
                ActionResult result = ctx.call_action("send_private_msg",
                                                      {
                                                          {"user_id", ctx.data["user_id"]},
                                                          {"message", "hello"},
                                                      });
            }
        }
    }

    void on_missed_action(ActionContext &ctx) override {
        if (enable_) {
            // 处理缺失的动作

            // 例如，处理 get_updates 动作
            if (ctx.action == "get_updates") {
                ctx.result.code = 200;
                ctx.result.data = {"foo", "bar"};
            }
        }
    }

private:
    bool enable_;
};

EXTENSION_CREATOR { return make_shared<SomeExtension>(); }
