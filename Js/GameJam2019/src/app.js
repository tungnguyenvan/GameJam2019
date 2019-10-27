
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        this._super();

        // init Touch event
        cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: this.onTouchBegan,
            onTouchMoved: this.onTouchMoved,
            onTouchEnded: this.onTouchEnded,
        }, this);

        // Schedule update everyframe
        this.scheduleUpdate();
        return true;
    },

    // Update function
    update : function(dt) {
    },

    // Touch began function
    onTouchBegan : function(touch, event) {
        cc.log("onTouchBegan");
        return true;
    },

    // Touch Move function
    onTouchMoved : function(touch, event) {
        cc.log("onTouchMoved");
        return true;
    },

    // Touch End function
    onTouchEnded : function(touch, event) {
        cc.log("onTouchEnded");
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

